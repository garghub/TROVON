static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 , V_5 ;
int V_6 ;
struct V_7 * V_8 ;
V_3 = F_2 ( & V_2 -> V_9 . V_10 ,
V_2 -> V_11 -> V_12 ) ;
if ( V_3 < 0 || V_3 >= V_2 -> V_11 -> V_12 ) {
F_3 ( V_2 -> V_11 -> V_13 , L_1 ) ;
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
F_3 ( V_2 -> V_11 -> V_13 ,
L_2 , V_3 , V_6 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_6 = 0 , V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 -> V_12 ; ++ V_4 ) {
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
const int V_35 =
V_2 -> V_36 -> V_37 *
V_2 -> V_36 -> V_38 . V_39 ;
int V_40 = V_29 / V_35 ;
if ( V_34 == NULL )
return;
if ( V_2 -> V_9 . V_41 + V_40 > V_34 -> V_42 ) {
int V_43 ;
V_43 = V_34 -> V_42 - V_2 -> V_9 . V_41 ;
if ( V_43 > 0 ) {
memcpy ( V_34 -> V_44 +
V_2 -> V_9 . V_41 * V_35 , V_28 ,
V_43 * V_35 ) ;
memcpy ( V_34 -> V_44 , V_28 + V_43 * V_35 ,
( V_40 - V_43 ) * V_35 ) ;
} else {
F_3 ( V_2 -> V_11 -> V_13 ,
L_3 , V_43 ) ;
}
} else {
memcpy ( V_34 -> V_44 +
V_2 -> V_9 . V_41 * V_35 , V_28 , V_29 ) ;
}
V_2 -> V_9 . V_41 += V_40 ;
if ( V_2 -> V_9 . V_41 >= V_34 -> V_42 )
V_2 -> V_9 . V_41 -= V_34 -> V_42 ;
}
void F_9 ( struct V_1 * V_2 , int V_21 )
{
struct V_30 * V_31 =
F_8 ( V_2 , V_32 ) ;
V_2 -> V_9 . V_45 += V_21 ;
if ( V_2 -> V_9 . V_45 >= V_2 -> V_9 . V_46 ) {
V_2 -> V_9 . V_45 %= V_2 -> V_9 . V_46 ;
F_10 ( & V_2 -> V_9 . V_47 ) ;
F_11 ( V_31 ) ;
F_12 ( & V_2 -> V_9 . V_47 ) ;
}
}
static void F_13 ( struct V_7 * V_7 )
{
int V_4 , V_3 , V_21 = 0 , V_48 = 0 ;
unsigned long V_49 ;
struct V_1 * V_2 = (struct V_1 * ) V_7 -> V_26 ;
V_2 -> V_9 . V_50 = V_7 -> V_51 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_11 -> V_12 ; ++ V_3 )
if ( V_7 == V_2 -> V_9 . V_15 [ V_3 ] )
break;
F_14 ( & V_2 -> V_9 . V_47 , V_49 ) ;
for ( V_4 = 0 ; V_4 < V_16 ; ++ V_4 ) {
char * V_28 ;
int V_29 ;
struct V_17 * V_18 = & V_7 -> V_19 [ V_4 ] ;
if ( V_18 -> V_52 == - V_53 ) {
V_48 = 1 ;
break;
}
V_28 = V_7 -> V_23 + V_18 -> V_20 ;
V_29 = V_18 -> V_54 ;
if ( V_29 > V_2 -> V_22 ) {
F_3 ( V_2 -> V_11 -> V_13 ,
L_4 ,
V_29 , V_2 -> V_22 ) ;
}
V_21 += V_29 ;
F_15 ( V_16 != 1 ,
L_5 ) ;
V_2 -> V_55 = V_28 ;
V_2 -> V_56 = V_29 /
( V_2 -> V_36 -> V_37 *
V_2 -> V_36 -> V_38 . V_39 ) ;
if ( ! F_16 ( V_57 , & V_2 -> V_9 . V_58 ) &&
F_16 ( V_59 , & V_2 -> V_9 . V_58 ) &&
V_29 > 0 )
F_7 ( V_2 , V_28 , V_29 ) ;
}
F_17 ( V_3 , & V_2 -> V_9 . V_10 ) ;
if ( F_18 ( V_3 , & V_2 -> V_9 . V_60 ) )
V_48 = 1 ;
if ( ! V_48 ) {
F_1 ( V_2 ) ;
if ( ! F_16 ( V_57 , & V_2 -> V_9 . V_58 ) &&
F_16 ( V_59 , & V_2 -> V_9 . V_58 ) )
F_9 ( V_2 , V_21 ) ;
}
F_19 ( & V_2 -> V_9 . V_47 , V_49 ) ;
}
static int F_20 ( struct V_30 * V_31 )
{
int V_61 ;
struct V_33 * V_34 = V_31 -> V_34 ;
struct V_1 * V_2 = F_21 ( V_31 ) ;
V_61 = F_22 ( V_34 , 0 ,
V_62 ,
& V_2 -> V_36 -> V_63 ) ;
if ( V_61 < 0 )
return V_61 ;
F_23 ( V_2 , V_64 , false ) ;
V_34 -> V_65 = V_2 -> V_36 -> V_38 ;
return 0 ;
}
static int F_24 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_21 ( V_31 ) ;
F_25 ( V_2 , V_64 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_66 * V_11 = V_2 -> V_11 ;
int V_4 ;
V_2 -> V_9 . V_15 = F_27 (
sizeof( struct V_7 * ) * V_11 -> V_12 , V_67 ) ;
if ( V_2 -> V_9 . V_15 == NULL )
return - V_68 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_12 ; ++ V_4 ) {
struct V_7 * V_7 ;
V_7 = V_2 -> V_9 . V_15 [ V_4 ] =
F_28 ( V_16 , V_67 ) ;
if ( V_7 == NULL )
return - V_68 ;
V_7 -> V_69 = V_11 -> V_70 ;
V_7 -> V_71 =
F_29 ( V_11 -> V_70 ,
V_11 -> V_36 -> V_72 &
V_73 ) ;
V_7 -> V_74 = V_75 ;
V_7 -> V_51 = - 1 ;
V_7 -> V_76 = V_16 ;
V_7 -> V_77 = V_78 ;
V_7 -> V_79 = 0 ;
V_7 -> V_80 = F_13 ;
}
return 0 ;
}
