struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 = NULL ;
struct V_8 * V_9 ;
int V_10 = 0 ;
if ( V_4 <= V_11 )
V_6 = V_3 -> V_12 ;
else
V_6 = V_3 -> V_13 ;
V_7 = F_2 ( V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( sizeof( * V_7 ) , V_14 ,
F_4 ( V_3 ) ) ;
if ( ! V_7 ) {
V_10 = - V_15 ;
goto V_16;
}
V_9 = & V_7 -> V_17 . V_9 ;
V_9 -> V_9 = F_5 ( V_3 -> V_18 ,
( V_19 |
V_20 |
V_21 |
V_22 ) ,
& V_6 -> V_23 ) ;
if ( F_6 ( V_9 -> V_9 ) ) {
V_10 = F_7 ( V_9 -> V_9 ) ;
V_9 -> V_9 = NULL ;
F_8 ( L_1 , V_24 , V_10 ) ;
goto V_16;
}
V_7 -> V_6 = V_6 ;
if ( V_6 -> V_25 == V_26 )
F_9 ( V_27 ) ;
else
F_9 ( V_28 ) ;
return V_7 ;
V_16:
F_10 ( V_7 ) ;
F_11 ( & V_6 -> V_29 ) ;
return F_12 ( V_10 ) ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_1 * V_7 , struct V_30 * V_31 ,
unsigned int V_32 )
{
struct V_33 * V_34 = V_3 -> V_34 ;
struct V_8 * V_9 = & V_7 -> V_17 . V_9 ;
struct V_30 * V_35 = V_31 ;
T_1 V_36 = 0 ;
T_1 * V_37 ;
T_2 V_38 ;
int V_39 , V_40 ;
int V_41 , V_42 ;
int V_43 ;
V_40 = F_14 ( V_34 , V_31 , V_32 , V_44 ) ;
if ( F_15 ( ! V_40 ) ) {
F_8 ( L_2 , V_24 ) ;
return - V_45 ;
}
V_38 = 0 ;
V_39 = 0 ;
for ( V_41 = 0 ; V_41 < V_40 ; ++ V_41 ) {
unsigned int V_46 = F_16 ( V_34 , & V_35 [ V_41 ] ) ;
T_1 V_47 = F_17 ( V_34 , & V_35 [ V_41 ] ) ;
if ( V_47 & ~ V_48 ) {
if ( V_41 > 0 ) {
F_18 ( V_34 , V_31 , V_32 ,
V_44 ) ;
return - V_49 ;
} else {
++ V_39 ;
}
}
if ( ( V_47 + V_46 ) & ~ V_48 ) {
if ( V_41 < V_40 - 1 ) {
F_18 ( V_34 , V_31 , V_32 ,
V_44 ) ;
return - V_49 ;
} else {
++ V_39 ;
}
}
V_38 += V_46 ;
}
V_39 += V_38 >> V_50 ;
if ( V_39 > V_7 -> V_6 -> V_23 . V_51 ) {
F_18 ( V_34 , V_31 , V_32 , V_44 ) ;
return - V_49 ;
}
V_37 = F_19 ( sizeof( T_1 ) * V_39 , V_52 ,
F_4 ( V_3 ) ) ;
if ( ! V_37 ) {
F_18 ( V_34 , V_31 , V_32 , V_44 ) ;
return - V_15 ;
}
V_39 = 0 ;
for ( V_41 = 0 ; V_41 < V_40 ; ++ V_41 ) {
unsigned int V_46 = F_16 ( V_34 , & V_35 [ V_41 ] ) ;
T_1 V_47 = F_17 ( V_34 , & V_35 [ V_41 ] ) ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 += V_53 )
V_37 [ V_39 ++ ] =
( V_47 & V_48 ) + V_42 ;
}
V_43 = F_20 ( V_9 -> V_9 , V_37 , V_39 , V_36 ) ;
if ( V_43 ) {
F_18 ( V_34 , V_31 , V_32 , V_44 ) ;
goto V_54;
}
F_21 ( V_7 ) ;
V_7 -> V_31 = V_35 ;
V_7 -> V_55 = V_32 ;
V_7 -> V_40 = V_40 ;
V_7 -> V_56 ++ ;
if ( V_7 -> V_6 -> V_25 == V_26 )
F_9 ( V_57 ) ;
else
F_9 ( V_58 ) ;
V_43 = 0 ;
V_54:
F_10 ( V_37 ) ;
return V_43 ;
}
struct V_1 * F_22 ( struct V_2 * V_3 ,
struct V_30 * V_31 ,
unsigned long V_32 ,
T_2 * V_59 )
{
struct V_1 * V_7 = NULL ;
struct V_8 * V_9 ;
int V_43 ;
V_7 = F_1 ( V_3 , V_32 ) ;
if ( F_6 ( V_7 ) )
return V_7 ;
V_7 -> V_60 = V_3 ;
V_9 = & V_7 -> V_17 . V_9 ;
V_43 = F_13 ( V_3 , V_7 , V_31 , V_32 ) ;
if ( V_43 == 0 )
* V_59 = V_9 -> V_9 -> V_61 ;
else
F_23 ( V_7 , 0 ) ;
return V_7 ;
}
void F_24 ( struct V_62 * V_63 , unsigned int * V_64 ,
unsigned long * V_65 , unsigned int V_66 )
{
struct V_1 * V_7 , * V_67 ;
struct V_8 * V_9 ;
F_25 ( V_68 ) ;
int V_43 = 0 ;
unsigned int V_69 = * V_64 ;
F_26 (ibmr, list, unmap_list) {
V_9 = & V_7 -> V_17 . V_9 ;
F_27 ( & V_9 -> V_9 -> V_63 , & V_68 ) ;
}
V_43 = F_28 ( & V_68 ) ;
if ( V_43 )
F_8 ( L_3 , V_43 ) ;
F_29 (ibmr, next, list, unmap_list) {
V_9 = & V_7 -> V_17 . V_9 ;
* V_65 += V_7 -> V_55 ;
F_30 ( V_7 ) ;
if ( V_69 < V_66 ||
V_7 -> V_56 >= V_7 -> V_6 -> V_23 . V_70 ) {
if ( V_7 -> V_6 -> V_25 == V_26 )
F_9 ( V_71 ) ;
else
F_9 ( V_72 ) ;
F_31 ( & V_7 -> V_73 ) ;
F_32 ( V_9 -> V_9 ) ;
F_10 ( V_7 ) ;
V_69 ++ ;
}
}
* V_64 = V_69 ;
}
void F_33 ( struct V_1 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_6 ;
if ( V_7 -> V_56 >= V_6 -> V_23 . V_70 )
F_34 ( & V_7 -> V_74 , & V_6 -> V_75 ) ;
else
F_34 ( & V_7 -> V_74 , & V_6 -> V_76 ) ;
}
