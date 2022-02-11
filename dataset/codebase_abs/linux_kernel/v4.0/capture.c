static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 , V_5 ;
int V_6 ;
struct V_7 * V_8 ;
V_3 =
F_2 ( & V_2 -> V_9 . V_10 , V_11 ) ;
if ( V_3 < 0 || V_3 >= V_11 ) {
F_3 ( V_2 -> V_12 -> V_13 , L_1 ) ;
return - V_14 ;
}
V_8 = V_2 -> V_9 . V_15 [ V_3 ] ;
V_5 = 0 ;
for ( V_4 = 0 ; V_4 < V_16 ; ++ V_4 ) {
struct V_17 * V_18 =
& V_8 -> V_19 [ V_4 ] ;
V_18 -> V_20 = V_5 ;
V_18 -> V_21 = V_2 -> V_22 ;
V_5 += V_2 -> V_22 ;
}
V_8 -> V_23 =
V_2 -> V_9 . V_24 +
V_3 * V_16 * V_2 -> V_22 ;
V_8 -> V_25 = V_5 ;
V_8 -> V_26 = V_2 ;
V_6 = F_4 ( V_8 , V_27 ) ;
if ( V_6 == 0 )
F_5 ( V_3 , & V_2 -> V_9 . V_10 ) ;
else
F_3 ( V_2 -> V_12 -> V_13 ,
L_2 , V_3 , V_6 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_6 = 0 , V_4 ;
for ( V_4 = 0 ; V_4 < V_11 ; ++ V_4 ) {
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
break;
}
return V_6 ;
}
void F_7 ( struct V_1 * V_2 , char * V_28 , int V_29 )
{
struct V_30 * V_31 =
F_8 ( V_2 , V_32 ) ;
struct V_33 * V_34 = V_31 -> V_34 ;
const int V_35 = V_2 -> V_36 -> V_35 ;
int V_37 = V_29 / V_35 ;
if ( V_34 == NULL )
return;
if ( V_2 -> V_9 . V_38 + V_37 > V_34 -> V_39 ) {
int V_40 ;
V_40 = V_34 -> V_39 - V_2 -> V_9 . V_38 ;
if ( V_40 > 0 ) {
memcpy ( V_34 -> V_41 +
V_2 -> V_9 . V_38 * V_35 , V_28 ,
V_40 * V_35 ) ;
memcpy ( V_34 -> V_41 , V_28 + V_40 * V_35 ,
( V_37 - V_40 ) * V_35 ) ;
} else {
F_3 ( V_2 -> V_12 -> V_13 ,
L_3 , V_40 ) ;
}
} else {
memcpy ( V_34 -> V_41 +
V_2 -> V_9 . V_38 * V_35 , V_28 , V_29 ) ;
}
V_2 -> V_9 . V_38 += V_37 ;
if ( V_2 -> V_9 . V_38 >= V_34 -> V_39 )
V_2 -> V_9 . V_38 -= V_34 -> V_39 ;
}
void F_9 ( struct V_1 * V_2 , int V_21 )
{
struct V_30 * V_31 =
F_8 ( V_2 , V_32 ) ;
V_2 -> V_9 . V_42 += V_21 ;
if ( V_2 -> V_9 . V_42 >= V_2 -> V_9 . V_43 ) {
V_2 -> V_9 . V_42 %= V_2 -> V_9 . V_43 ;
F_10 ( & V_2 -> V_9 . V_44 ) ;
F_11 ( V_31 ) ;
F_12 ( & V_2 -> V_9 . V_44 ) ;
}
}
static void F_13 ( struct V_7 * V_7 )
{
int V_4 , V_3 , V_21 = 0 , V_45 = 0 ;
unsigned long V_46 ;
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_26 ;
V_2 -> V_9 . V_47 = V_7 -> V_48 ;
for ( V_3 = 0 ; V_3 < V_11 ; ++ V_3 )
if ( V_7 == V_2 -> V_9 . V_15 [ V_3 ] )
break;
F_14 ( & V_2 -> V_9 . V_44 , V_46 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; ++ V_4 ) {
char * V_28 ;
int V_29 ;
struct V_17 * V_18 = & V_7 -> V_19 [ V_4 ] ;
if ( V_18 -> V_49 == - V_50 ) {
V_45 = 1 ;
break;
}
V_28 = V_7 -> V_23 + V_18 -> V_20 ;
V_29 = V_18 -> V_51 ;
if ( V_29 > V_2 -> V_22 ) {
F_3 ( V_2 -> V_12 -> V_13 ,
L_4 ,
V_29 , V_2 -> V_22 ) ;
}
V_21 += V_29 ;
V_2 -> V_52 = V_28 ;
V_2 -> V_53 = V_29 ;
if ( ! F_15 ( V_54 , & V_2 -> V_9 . V_55 ) &&
F_15 ( V_56 , & V_2 -> V_9 . V_55 ) &&
V_29 > 0 )
F_7 ( V_2 , V_28 , V_29 ) ;
}
F_16 ( V_3 , & V_2 -> V_9 . V_10 ) ;
if ( F_17 ( V_3 , & V_2 -> V_9 . V_57 ) )
V_45 = 1 ;
if ( ! V_45 ) {
F_1 ( V_2 ) ;
if ( ! F_15 ( V_54 , & V_2 -> V_9 . V_55 ) &&
F_15 ( V_56 , & V_2 -> V_9 . V_55 ) )
F_9 ( V_2 , V_21 ) ;
}
F_18 ( & V_2 -> V_9 . V_44 , V_46 ) ;
}
static int F_19 ( struct V_30 * V_31 )
{
int V_58 ;
struct V_33 * V_34 = V_31 -> V_34 ;
struct V_1 * V_2 = F_20 ( V_31 ) ;
V_58 = F_21 ( V_34 , 0 ,
V_59 ,
& V_2 -> V_36 -> V_60 ) ;
if ( V_58 < 0 )
return V_58 ;
V_34 -> V_61 = V_2 -> V_36 -> V_62 ;
return 0 ;
}
static int F_22 ( struct V_30 * V_31 )
{
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_63 * V_12 = V_2 -> V_12 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 ; ++ V_4 ) {
struct V_7 * V_7 ;
V_7 = V_2 -> V_9 . V_15 [ V_4 ] =
F_24 ( V_16 , V_64 ) ;
if ( V_7 == NULL )
return - V_65 ;
V_7 -> V_66 = V_12 -> V_67 ;
V_7 -> V_68 =
F_25 ( V_12 -> V_67 ,
V_12 -> V_36 -> V_69 &
V_70 ) ;
V_7 -> V_71 = V_72 ;
V_7 -> V_48 = - 1 ;
V_7 -> V_73 = V_16 ;
V_7 -> V_74 = V_75 ;
V_7 -> V_76 = 0 ;
V_7 -> V_77 = F_13 ;
}
return 0 ;
}
