static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
return F_4 ( V_7 -> V_8 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_6 ( V_9 , V_7 -> V_8 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
switch ( V_10 ) {
case - 1 :
F_8 ( V_11 , 0 , V_12 ) ;
F_8 ( V_13 , 0 , V_12 ) ;
F_9 ( & V_14 , V_7 -> V_15 ) ;
break;
case 0 :
F_10 ( & V_14 , V_7 -> V_15 ) ;
F_8 ( 0 , V_13 , V_12 ) ;
F_8 ( 0 , V_11 , V_12 ) ;
break;
default:
F_11 () ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_16 , unsigned int V_17 )
{
if ( V_16 == V_18 )
return;
if ( V_17 & V_19 )
F_5 ( V_2 , V_20 , V_16 ) ;
else if ( V_17 & V_21 )
F_5 ( V_2 , V_22 , V_16 ) ;
while ( ( F_13 ( V_23 ) & V_24 ) == 0 )
;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_13 ( V_23 ) & V_25 ;
}
static unsigned char F_15 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_26 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 * V_27 , int V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
V_27 [ V_29 ] = F_1 ( V_2 , V_30 ) ;
}
static void F_17 ( struct V_1 * V_2 , const T_2 * V_27 , int V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
F_5 ( V_2 , V_30 , V_27 [ V_29 ] ) ;
}
static int F_18 ( struct V_31 * V_32 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_35 ;
T_3 V_36 ;
T_3 V_37 = 0 ;
V_7 = F_19 ( & V_32 -> V_38 , sizeof( struct V_6 ) ,
V_39 ) ;
if ( ! V_7 )
return - V_40 ;
V_34 = F_20 ( V_32 , V_41 , 0 ) ;
V_7 -> V_8 = F_21 ( & V_32 -> V_38 , V_34 ) ;
if ( F_22 ( V_7 -> V_8 ) )
return F_23 ( V_7 -> V_8 ) ;
F_24 ( & V_7 -> V_5 , V_32 -> V_38 . V_42 ) ;
V_2 = F_25 ( & V_7 -> V_5 ) ;
V_2 -> V_38 . V_43 = & V_32 -> V_38 ;
V_7 -> V_5 . V_44 = F_12 ;
V_7 -> V_5 . V_45 = F_14 ;
V_7 -> V_5 . V_46 = F_7 ;
V_7 -> V_5 . V_47 = F_17 ;
V_7 -> V_5 . V_48 = F_16 ;
V_7 -> V_5 . V_49 = F_15 ;
V_7 -> V_5 . V_50 = 30 ;
V_7 -> V_5 . V_51 . V_52 = V_53 ;
V_7 -> V_5 . V_51 . V_54 = V_55 ;
F_26 ( V_32 , V_7 ) ;
F_27 ( & V_7 -> V_5 , V_7 ) ;
V_35 = F_28 ( V_32 -> V_38 . V_42 , L_1 , & V_36 ) ;
if ( ! V_35 && V_36 == 1 )
V_37 = V_56 | V_57 ;
F_29 ( F_30 ( V_7 -> V_8 )
| F_31 ( 3 ) | V_58 , V_59 ) ;
F_29 ( V_60 | V_61 | V_62
| V_63 | V_64 | V_65
| V_66 , V_67 ) ;
F_29 ( V_13 | V_68 | V_69
| V_70 | V_71 | V_72
| V_37 , V_12 ) ;
V_35 = F_32 ( V_2 , 1 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_2 , NULL , 0 ) ;
if ( V_35 )
F_34 ( V_2 ) ;
return V_35 ;
}
static int F_35 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = F_36 ( V_32 ) ;
F_34 ( F_25 ( & V_7 -> V_5 ) ) ;
return 0 ;
}
