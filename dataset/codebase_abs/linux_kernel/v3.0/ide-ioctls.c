int F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_4 , unsigned long V_5 ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 ;
int V_10 = - V_11 ;
for (; ( V_9 = V_7 -> V_12 ) ; V_7 ++ ) {
if ( V_9 -> V_13 && V_7 -> V_14 == V_4 )
goto V_15;
else if ( V_9 -> V_16 && V_7 -> V_17 == V_4 )
goto V_18;
}
return V_10 ;
V_15:
F_2 ( & V_19 ) ;
V_10 = V_9 -> V_13 ( V_1 ) ;
F_3 ( & V_19 ) ;
return V_10 >= 0 ? F_4 ( V_10 , ( long V_20 * ) V_5 ) : V_10 ;
V_18:
if ( V_3 != V_3 -> V_21 )
V_10 = - V_22 ;
else {
if ( ! F_5 ( V_23 ) )
V_10 = - V_24 ;
else {
F_2 ( & V_19 ) ;
V_10 = F_6 ( V_1 , V_9 , V_5 ) ;
F_3 ( & V_19 ) ;
}
}
return V_10 ;
}
static int F_7 ( T_1 * V_1 , unsigned int V_4 ,
unsigned long V_5 )
{
T_2 * V_25 = NULL ;
int V_26 = ( V_4 == V_27 ) ? ( V_28 * 2 ) : 142 ;
int V_29 = 0 ;
if ( ( V_1 -> V_30 & V_31 ) == 0 ) {
V_29 = - V_32 ;
goto V_33;
}
V_25 = F_8 ( V_28 * 2 , V_34 ) ;
if ( V_25 == NULL ) {
V_29 = - V_35 ;
goto V_33;
}
memcpy ( V_25 , V_1 -> V_25 , V_26 ) ;
F_9 ( V_25 ) ;
if ( F_10 ( ( void V_20 * ) V_5 , V_25 , V_26 ) )
V_29 = - V_36 ;
F_11 ( V_25 ) ;
V_33:
return V_29 ;
}
static int F_12 ( T_1 * V_1 , unsigned long V_5 )
{
return F_4 ( ( ! ! ( V_1 -> V_30 & V_37 )
<< V_38 ) |
( ! ! ( V_1 -> V_30 & V_39 )
<< V_40 ) , ( long V_20 * ) V_5 ) ;
}
static int F_13 ( T_1 * V_1 , unsigned long V_5 )
{
if ( V_5 != ( V_5 & ( ( 1 << V_38 ) | ( 1 << V_40 ) ) ) )
return - V_41 ;
if ( ( ( V_5 >> V_38 ) & 1 ) &&
( V_1 -> V_42 != V_43 ) )
return - V_41 ;
if ( ( V_5 >> V_38 ) & 1 )
V_1 -> V_30 |= V_37 ;
else
V_1 -> V_30 &= ~ V_37 ;
if ( ( V_5 >> V_40 ) & 1 )
V_1 -> V_30 |= V_39 ;
else
V_1 -> V_30 &= ~ V_39 ;
return 0 ;
}
static int F_14 ( T_1 * V_1 , unsigned long V_5 )
{
T_3 * V_44 = NULL ;
int V_45 = 0 , V_10 = 0 ;
T_3 args [ 4 ] , V_46 = 0 ;
struct V_47 V_4 ;
struct V_48 * V_49 = & V_4 . V_49 ;
if ( NULL == ( void * ) V_5 ) {
struct V_50 * V_51 ;
V_51 = F_15 ( V_1 -> V_52 , V_53 , V_54 ) ;
V_51 -> V_55 = V_56 ;
V_10 = F_16 ( V_1 -> V_52 , NULL , V_51 , 0 ) ;
F_17 ( V_51 ) ;
return V_10 ;
}
if ( F_18 ( args , ( void V_20 * ) V_5 , 4 ) )
return - V_36 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_49 -> V_57 = args [ 2 ] ;
if ( args [ 0 ] == V_58 ) {
V_49 -> V_59 = args [ 3 ] ;
V_49 -> V_60 = args [ 1 ] ;
V_49 -> V_61 = 0x4f ;
V_49 -> V_62 = 0xc2 ;
V_4 . V_63 . V_33 . V_49 = V_64 ;
V_4 . V_63 . V_65 . V_49 = V_66 ;
} else {
V_49 -> V_59 = args [ 1 ] ;
V_4 . V_63 . V_33 . V_49 = V_67 | V_66 ;
V_4 . V_63 . V_65 . V_49 = V_66 ;
}
V_49 -> V_68 = args [ 0 ] ;
V_4 . V_69 = args [ 3 ] ? V_70 : V_71 ;
if ( args [ 3 ] ) {
V_4 . V_72 |= V_73 ;
V_45 = V_74 * args [ 3 ] ;
V_44 = F_19 ( V_45 , V_34 ) ;
if ( V_44 == NULL )
return - V_35 ;
}
if ( V_49 -> V_68 == V_75 &&
V_49 -> V_57 == V_76 &&
V_49 -> V_59 >= V_77 ) {
V_46 = F_20 ( V_1 , V_49 -> V_59 ) ;
if ( V_46 != V_49 -> V_59 ) {
V_10 = - V_22 ;
goto abort;
}
V_4 . V_72 |= V_78 ;
}
V_10 = F_21 ( V_1 , & V_4 , V_44 , args [ 3 ] ) ;
args [ 0 ] = V_49 -> V_79 ;
args [ 1 ] = V_49 -> error ;
args [ 2 ] = V_49 -> V_59 ;
abort:
if ( F_10 ( ( void V_20 * ) V_5 , & args , 4 ) )
V_10 = - V_36 ;
if ( V_44 ) {
if ( F_10 ( ( void V_20 * ) ( V_5 + 4 ) , V_44 , V_45 ) )
V_10 = - V_36 ;
F_11 ( V_44 ) ;
}
return V_10 ;
}
static int F_22 ( T_1 * V_1 , unsigned long V_5 )
{
void V_20 * V_80 = ( void V_20 * ) V_5 ;
int V_10 = 0 ;
T_3 args [ 7 ] ;
struct V_47 V_4 ;
if ( F_18 ( args , V_80 , 7 ) )
return - V_36 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
memcpy ( & V_4 . V_49 . V_57 , & args [ 1 ] , 6 ) ;
V_4 . V_49 . V_68 = args [ 0 ] ;
V_4 . V_63 . V_33 . V_49 = V_64 | V_81 ;
V_4 . V_63 . V_65 . V_49 = V_82 | V_81 ;
V_10 = F_23 ( V_1 , & V_4 ) ;
args [ 0 ] = V_4 . V_49 . V_68 ;
memcpy ( & args [ 1 ] , & V_4 . V_49 . V_57 , 6 ) ;
if ( F_10 ( V_80 , args , 7 ) )
V_10 = - V_36 ;
return V_10 ;
}
static int F_24 ( T_1 * V_1 )
{
struct V_50 * V_51 ;
int V_83 = 0 ;
V_51 = F_15 ( V_1 -> V_52 , V_53 , V_54 ) ;
V_51 -> V_55 = V_84 ;
V_51 -> V_85 = 1 ;
V_51 -> V_4 [ 0 ] = V_86 ;
if ( F_16 ( V_1 -> V_52 , NULL , V_51 , 1 ) )
V_83 = V_51 -> V_87 ;
F_17 ( V_51 ) ;
return V_83 ;
}
int F_25 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_4 , unsigned long V_5 )
{
int V_10 ;
V_10 = F_1 ( V_1 , V_3 , V_4 , V_5 , V_88 ) ;
if ( V_10 != - V_11 )
return V_10 ;
switch ( V_4 ) {
case V_89 :
case V_27 :
if ( V_3 != V_3 -> V_21 )
return - V_22 ;
return F_7 ( V_1 , V_4 , V_5 ) ;
case V_90 :
return F_12 ( V_1 , V_5 ) ;
case V_91 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
return F_13 ( V_1 , V_5 ) ;
#ifdef F_26
case V_92 :
if ( ! F_5 ( V_23 ) || ! F_5 ( V_93 ) )
return - V_24 ;
if ( V_1 -> V_42 == V_94 )
return F_27 ( V_1 , V_5 ) ;
return - V_32 ;
#endif
case V_95 :
if ( ! F_5 ( V_93 ) )
return - V_24 ;
return F_14 ( V_1 , V_5 ) ;
case V_96 :
if ( ! F_5 ( V_93 ) )
return - V_24 ;
return F_22 ( V_1 , V_5 ) ;
case V_97 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
return F_24 ( V_1 ) ;
case V_98 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
if ( F_4 ( V_99 , ( long V_20 * ) V_5 ) )
return - V_36 ;
return 0 ;
case V_100 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
return - V_11 ;
default:
return - V_22 ;
}
}
