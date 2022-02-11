void
F_1 ( char * V_1 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
if ( V_5 <= 0 )
return;
if ( ! V_1 )
return;
if ( ! * V_1 )
return;
if ( ! ( V_3 = F_2 ( sizeof( struct V_2 ) + strlen ( V_1 ) , V_6 ) ) )
return;
strcpy ( V_3 -> V_7 , V_1 ) ;
V_3 -> V_8 = NULL ;
F_3 ( & V_9 , V_4 ) ;
V_3 -> V_10 = V_5 ;
if ( ! V_11 )
V_11 = V_3 ;
else
V_12 -> V_8 = V_3 ;
V_12 = V_3 ;
while ( V_11 -> V_8 ) {
if ( ( V_11 -> V_10 <= 0 ) &&
( V_11 -> V_8 -> V_10 <= 0 ) ) {
V_3 = V_11 ;
V_11 = V_11 -> V_8 ;
F_4 ( V_3 ) ;
} else
break;
}
F_5 ( & V_9 , V_4 ) ;
F_6 ( & ( V_13 ) ) ;
}
static T_1
F_7 ( struct V_14 * V_14 , char T_2 * V_15 , T_3 V_16 , T_4 * V_17 )
{
struct V_2 * V_18 ;
int V_19 ;
if ( ! ( V_18 = * ( (struct V_2 * * ) V_14 -> V_20 ) ) ) {
if ( V_14 -> V_21 & V_22 )
return - V_23 ;
F_8 ( V_13 , ( V_18 =
* ( (struct V_2 * * ) V_14 -> V_20 ) ) ) ;
}
if ( ! V_18 )
return ( 0 ) ;
V_18 -> V_10 -- ;
V_14 -> V_20 = & V_18 -> V_8 ;
if ( ( V_19 = strlen ( V_18 -> V_7 ) ) <= V_16 ) {
if ( F_9 ( V_15 , V_18 -> V_7 , V_19 ) )
return - V_24 ;
* V_17 += V_19 ;
return ( V_19 ) ;
}
return ( 0 ) ;
}
static T_1
F_10 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 )
{
return ( - V_25 ) ;
}
static unsigned int
F_11 ( struct V_14 * V_14 , T_5 * V_26 )
{
unsigned int V_27 = 0 ;
F_12 ( V_14 , & ( V_13 ) , V_26 ) ;
if ( * ( (struct V_2 * * ) V_14 -> V_20 ) ) {
V_27 |= V_28 | V_29 ;
}
return V_27 ;
}
static int
F_13 ( struct V_30 * V_31 , struct V_14 * V_32 )
{
unsigned long V_4 ;
F_3 ( & V_9 , V_4 ) ;
V_5 ++ ;
if ( V_11 )
V_32 -> V_20 = & ( V_12 -> V_8 ) ;
else
V_32 -> V_20 = & V_11 ;
F_5 ( & V_9 , V_4 ) ;
return F_14 ( V_31 , V_32 ) ;
}
static int
F_15 ( struct V_30 * V_31 , struct V_14 * V_32 )
{
struct V_2 * V_18 ;
unsigned long V_4 ;
F_3 ( & V_9 , V_4 ) ;
V_5 -- ;
V_18 = * ( (struct V_2 * * ) V_32 -> V_20 ) ;
while ( V_18 ) {
V_18 -> V_10 -- ;
V_18 = V_18 -> V_8 ;
}
if ( V_5 <= 0 )
while ( V_11 ) {
V_18 = V_11 ;
V_11 = V_11 -> V_8 ;
F_4 ( V_18 ) ;
}
F_5 ( & V_9 , V_4 ) ;
return ( 0 ) ;
}
static int F_16 ( struct V_14 * V_14 , T_6 V_33 , T_7 V_34 )
{
T_8 V_35 ;
int V_36 ;
unsigned long V_4 ;
T_9 * V_37 ;
char * V_1 ;
if ( F_17 ( & V_35 , ( void T_2 * ) V_34 , sizeof( V_35 ) ) )
return - V_24 ;
switch ( V_33 ) {
case V_38 :
V_35 . V_39 = V_40 ;
break;
case V_41 :
if ( ( V_35 . V_42 . V_43 = V_44 . V_45 ( V_35 . V_42 . V_46 ) ) < 0 )
return ( - V_47 ) ;
break;
case V_48 :
V_1 = V_44 . V_49 ( V_35 . V_42 . V_43 ) ;
if ( ! V_1 )
return ( - V_47 ) ;
if ( ! * V_1 )
return ( - V_47 ) ;
strcpy ( V_35 . V_42 . V_46 , V_1 ) ;
break;
case V_50 :
if ( ! ( V_37 = F_18 ( V_35 . V_51 . V_52 ) ) )
return ( - V_47 ) ;
V_35 . V_51 . V_53 = * V_37 ;
break;
case V_54 :
if ( ! ( V_37 = F_18 ( V_35 . V_51 . V_52 ) ) )
return ( - V_47 ) ;
F_3 ( & V_55 , V_4 ) ;
* V_37 = V_35 . V_51 . V_53 ;
F_5 ( & V_55 , V_4 ) ;
return ( 0 ) ;
break;
case V_56 :
return ( F_19 ( V_35 . V_51 . V_52 , & V_35 . V_51 . V_53 ) ) ;
break;
case V_57 :
return ( F_20 ( V_35 . V_51 . V_52 ) ) ;
break;
case V_58 :
return ( F_21 ( V_35 . V_59 . V_60 ,
V_35 . V_59 . V_61 ,
V_35 . V_59 . V_62 ) ) ;
case V_63 :
case V_64 :
case V_65 :
if ( ! V_44 . V_49 ( V_35 . V_66 . V_43 ) )
return ( - V_47 ) ;
if ( F_22 ( V_35 . V_66 . V_67 , sizeof( V_35 . V_66 . V_67 ) ) ==
sizeof( V_35 . V_66 . V_67 ) )
return - V_47 ;
if ( F_22 ( V_35 . V_66 . V_68 , sizeof( V_35 . V_66 . V_68 ) ) ==
sizeof( V_35 . V_66 . V_68 ) )
return - V_47 ;
if ( ( V_36 = F_23 ( V_35 . V_66 . V_43 ,
( V_33 == V_63 ) ? 1 : ( V_33 == V_64 ) ? 0 : 2 ,
V_35 . V_66 . V_69 ,
V_35 . V_66 . V_67 ,
V_35 . V_66 . V_70 ,
V_35 . V_66 . V_68 ,
& V_35 . V_66 . V_71 ) ) )
return ( V_36 ) ;
break;
default:
return ( - V_47 ) ;
}
return F_9 ( ( void T_2 * ) V_34 , & V_35 , sizeof( V_35 ) ) ? - V_24 : 0 ;
}
static long F_24 ( struct V_14 * V_14 , T_6 V_33 , T_7 V_34 )
{
long V_72 ;
F_25 ( & V_73 ) ;
V_72 = F_16 ( V_14 , V_33 , V_34 ) ;
F_26 ( & V_73 ) ;
return V_72 ;
}
int
F_27 ( void )
{
F_28 ( & V_13 ) ;
#ifdef F_29
V_74 = F_30 ( L_1 , V_75 . V_76 ) ;
if ( ! V_74 )
return ( - 1 ) ;
V_77 = F_31 ( L_2 , V_78 | V_79 ,
V_74 , & V_80 ) ;
if ( ! V_77 ) {
F_32 ( L_1 , V_75 . V_76 ) ;
return ( - 1 ) ;
}
#endif
return ( 0 ) ;
}
int
F_33 ( void )
{
#ifdef F_29
F_32 ( L_2 , V_74 ) ;
F_32 ( L_1 , V_75 . V_76 ) ;
#endif
return ( 0 ) ;
}
