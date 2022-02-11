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
F_16 ( V_51 ) -> type = V_55 ;
F_17 ( V_1 -> V_52 , NULL , V_51 , 0 ) ;
V_10 = F_18 ( V_51 ) -> V_56 ? - V_57 : 0 ;
F_19 ( V_51 ) ;
return V_10 ;
}
if ( F_20 ( args , ( void V_20 * ) V_5 , 4 ) )
return - V_36 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_49 -> V_58 = args [ 2 ] ;
if ( args [ 0 ] == V_59 ) {
V_49 -> V_60 = args [ 3 ] ;
V_49 -> V_61 = args [ 1 ] ;
V_49 -> V_62 = V_63 ;
V_49 -> V_64 = V_65 ;
V_4 . V_66 . V_33 . V_49 = V_67 ;
V_4 . V_66 . V_68 . V_49 = V_69 ;
} else {
V_49 -> V_60 = args [ 1 ] ;
V_4 . V_66 . V_33 . V_49 = V_70 | V_69 ;
V_4 . V_66 . V_68 . V_49 = V_69 ;
}
V_49 -> V_71 = args [ 0 ] ;
V_4 . V_72 = args [ 3 ] ? V_73 : V_74 ;
if ( args [ 3 ] ) {
V_4 . V_75 |= V_76 ;
V_45 = V_77 * args [ 3 ] ;
V_44 = F_21 ( V_45 , V_34 ) ;
if ( V_44 == NULL )
return - V_35 ;
}
if ( V_49 -> V_71 == V_78 &&
V_49 -> V_58 == V_79 &&
V_49 -> V_60 >= V_80 ) {
V_46 = F_22 ( V_1 , V_49 -> V_60 ) ;
if ( V_46 != V_49 -> V_60 ) {
V_10 = - V_22 ;
goto abort;
}
V_4 . V_75 |= V_81 ;
}
V_10 = F_23 ( V_1 , & V_4 , V_44 , args [ 3 ] ) ;
args [ 0 ] = V_49 -> V_82 ;
args [ 1 ] = V_49 -> error ;
args [ 2 ] = V_49 -> V_60 ;
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
static int F_24 ( T_1 * V_1 , unsigned long V_5 )
{
void V_20 * V_83 = ( void V_20 * ) V_5 ;
int V_10 = 0 ;
T_3 args [ 7 ] ;
struct V_47 V_4 ;
if ( F_20 ( args , V_83 , 7 ) )
return - V_36 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
memcpy ( & V_4 . V_49 . V_58 , & args [ 1 ] , 6 ) ;
V_4 . V_49 . V_71 = args [ 0 ] ;
V_4 . V_66 . V_33 . V_49 = V_67 | V_84 ;
V_4 . V_66 . V_68 . V_49 = V_85 | V_84 ;
V_10 = F_25 ( V_1 , & V_4 ) ;
args [ 0 ] = V_4 . V_49 . V_71 ;
memcpy ( & args [ 1 ] , & V_4 . V_49 . V_58 , 6 ) ;
if ( F_10 ( V_83 , args , 7 ) )
V_10 = - V_36 ;
return V_10 ;
}
static int F_26 ( T_1 * V_1 )
{
struct V_50 * V_51 ;
int V_86 = 0 ;
V_51 = F_15 ( V_1 -> V_52 , V_53 , V_54 ) ;
F_16 ( V_51 ) -> type = V_87 ;
F_18 ( V_51 ) -> V_88 = 1 ;
F_18 ( V_51 ) -> V_4 [ 0 ] = V_89 ;
F_17 ( V_1 -> V_52 , NULL , V_51 , 1 ) ;
V_86 = F_18 ( V_51 ) -> V_56 ;
F_19 ( V_51 ) ;
return V_86 ;
}
int F_27 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_4 , unsigned long V_5 )
{
int V_10 ;
V_10 = F_1 ( V_1 , V_3 , V_4 , V_5 , V_90 ) ;
if ( V_10 != - V_11 )
return V_10 ;
switch ( V_4 ) {
case V_91 :
case V_27 :
if ( V_3 != V_3 -> V_21 )
return - V_22 ;
return F_7 ( V_1 , V_4 , V_5 ) ;
case V_92 :
return F_12 ( V_1 , V_5 ) ;
case V_93 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
return F_13 ( V_1 , V_5 ) ;
#ifdef F_28
case V_94 :
if ( ! F_5 ( V_23 ) || ! F_5 ( V_95 ) )
return - V_24 ;
if ( V_1 -> V_42 == V_96 )
return F_29 ( V_1 , V_5 ) ;
return - V_32 ;
#endif
case V_97 :
if ( ! F_5 ( V_95 ) )
return - V_24 ;
return F_14 ( V_1 , V_5 ) ;
case V_98 :
if ( ! F_5 ( V_95 ) )
return - V_24 ;
return F_24 ( V_1 , V_5 ) ;
case V_99 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
return F_26 ( V_1 ) ;
case V_100 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
if ( F_4 ( V_101 , ( long V_20 * ) V_5 ) )
return - V_36 ;
return 0 ;
case V_102 :
if ( ! F_5 ( V_23 ) )
return - V_24 ;
return - V_11 ;
default:
return - V_22 ;
}
}
