int F_1 ( const char * V_1 ,
T_1 V_2 ,
const void * V_3 ,
const void * V_4 ,
struct V_5 * V_6 )
{
if ( V_3 == NULL && V_4 == NULL ) {
return F_2 ( V_1 , V_6 ) ;
} else if ( V_3 != NULL && V_4 != NULL ) {
switch ( V_2 ) {
case V_7 :
return F_3 ( V_1 , V_3 , V_4 ,
V_6 ) ;
default:
return - V_8 ;
}
} else
return - V_9 ;
}
int F_4 ( const char * V_1 ,
T_1 V_2 ,
const void * V_3 ,
const void * V_4 ,
struct V_5 * V_6 )
{
int V_10 = - V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = NULL ;
const struct V_20 * V_21 , * V_22 ;
const struct V_23 * V_24 , * V_25 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_26 ) ;
if ( V_13 == NULL )
return - V_11 ;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_26 ) ;
if ( V_13 -> V_1 == NULL )
goto V_27;
}
if ( V_3 == NULL && V_4 == NULL )
V_13 -> type = V_28 ;
else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_26 ) ;
if ( V_15 == NULL )
goto V_27;
F_7 ( & V_15 -> V_29 ) ;
F_7 ( & V_15 -> V_30 ) ;
switch ( V_2 ) {
case V_7 :
V_21 = V_3 ;
V_22 = V_4 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_26 ) ;
if ( V_17 == NULL )
goto V_27;
V_17 -> type = V_28 ;
V_17 -> V_31 . V_3 = V_21 -> V_32 & V_22 -> V_32 ;
V_17 -> V_31 . V_4 = V_22 -> V_32 ;
V_17 -> V_31 . V_33 = 1 ;
V_10 = F_8 ( & V_17 -> V_31 ,
& V_15 -> V_29 ) ;
if ( V_10 != 0 )
goto V_27;
break;
case V_34 :
V_24 = V_3 ;
V_25 = V_4 ;
V_19 = F_5 ( sizeof( * V_19 ) , V_26 ) ;
if ( V_19 == NULL )
goto V_27;
V_19 -> type = V_28 ;
F_9 ( & V_19 -> V_31 . V_3 , V_24 ) ;
V_19 -> V_31 . V_3 . V_35 [ 0 ] &= V_25 -> V_35 [ 0 ] ;
V_19 -> V_31 . V_3 . V_35 [ 1 ] &= V_25 -> V_35 [ 1 ] ;
V_19 -> V_31 . V_3 . V_35 [ 2 ] &= V_25 -> V_35 [ 2 ] ;
V_19 -> V_31 . V_3 . V_35 [ 3 ] &= V_25 -> V_35 [ 3 ] ;
F_9 ( & V_19 -> V_31 . V_4 , V_25 ) ;
V_19 -> V_31 . V_33 = 1 ;
V_10 = F_8 ( & V_17 -> V_31 ,
& V_15 -> V_29 ) ;
if ( V_10 != 0 )
goto V_27;
break;
default:
goto V_27;
break;
}
V_13 -> V_36 . V_37 = V_15 ;
V_13 -> type = V_38 ;
} else {
V_10 = - V_9 ;
goto V_27;
}
V_10 = F_10 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_27;
return 0 ;
V_27:
F_11 ( V_13 -> V_1 ) ;
F_11 ( V_13 ) ;
F_11 ( V_15 ) ;
F_11 ( V_17 ) ;
F_11 ( V_19 ) ;
return V_10 ;
}
int F_12 ( struct V_39 * V_39 ,
const char * V_40 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
T_2 V_41 ,
struct V_5 * V_6 )
{
T_2 V_42 ;
switch ( V_2 ) {
case V_7 :
V_42 = sizeof( struct V_20 ) ;
break;
case V_34 :
V_42 = sizeof( struct V_23 ) ;
break;
default:
return - V_8 ;
}
return F_13 ( V_39 ,
V_40 , V_3 , V_4 , V_42 ,
V_41 , V_6 ) ;
}
int F_14 ( struct V_39 * V_39 ,
const char * V_40 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
struct V_5 * V_6 )
{
T_2 V_42 ;
switch ( V_2 ) {
case V_7 :
V_42 = sizeof( struct V_20 ) ;
break;
case V_34 :
V_42 = sizeof( struct V_23 ) ;
break;
default:
return - V_8 ;
}
return F_15 ( V_39 ,
V_40 , V_3 , V_4 , V_42 ,
V_6 ) ;
}
int F_16 ( struct V_43 * V_44 ,
struct V_5 * V_6 )
{
return F_17 ( V_44 , V_6 ) ;
}
void F_18 ( T_2 V_45 , struct V_5 * V_6 )
{
F_19 ( V_45 , V_6 ) ;
}
int F_20 ( T_2 V_45 ,
const char * V_1 ,
const struct V_20 * V_3 ,
const struct V_20 * V_4 ,
struct V_5 * V_6 )
{
int V_10 = - V_11 ;
struct V_43 * V_44 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_46 = NULL ;
V_44 = F_21 ( V_45 ) ;
if ( V_44 == NULL )
return - V_47 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_26 ) ;
if ( V_13 == NULL )
return - V_11 ;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_26 ) ;
if ( V_13 -> V_1 == NULL )
goto V_48;
}
if ( V_3 == NULL && V_4 == NULL ) {
V_13 -> V_36 . V_49 = V_44 ;
V_13 -> type = V_50 ;
} else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_26 ) ;
if ( V_15 == NULL )
goto V_48;
F_7 ( & V_15 -> V_29 ) ;
F_7 ( & V_15 -> V_30 ) ;
V_46 = F_5 ( sizeof( * V_46 ) , V_26 ) ;
if ( V_46 == NULL )
goto V_48;
V_46 -> V_36 . V_49 = V_44 ;
V_46 -> type = V_50 ;
V_46 -> V_31 . V_3 = V_3 -> V_32 & V_4 -> V_32 ;
V_46 -> V_31 . V_4 = V_4 -> V_32 ;
V_46 -> V_31 . V_33 = 1 ;
V_10 = F_8 ( & V_46 -> V_31 , & V_15 -> V_29 ) ;
if ( V_10 != 0 )
goto V_48;
V_13 -> V_36 . V_37 = V_15 ;
V_13 -> type = V_38 ;
} else {
V_10 = - V_9 ;
goto V_48;
}
V_10 = F_10 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_48;
return 0 ;
V_48:
F_22 ( V_44 ) ;
F_11 ( V_13 -> V_1 ) ;
F_11 ( V_13 ) ;
F_11 ( V_15 ) ;
F_11 ( V_46 ) ;
return V_10 ;
}
int F_23 ( struct V_51 * V_52 ,
T_2 V_53 )
{
struct V_51 * V_54 = V_52 ;
T_2 V_55 ;
T_2 V_56 ;
T_3 V_57 ;
if ( V_53 > V_54 -> V_58 ) {
while ( V_53 >= ( V_54 -> V_58 + V_59 ) ) {
V_54 = V_54 -> V_60 ;
if ( V_54 == NULL )
return - V_47 ;
}
V_55 = ( V_53 - V_54 -> V_58 ) / V_61 ;
V_56 = V_53 - V_54 -> V_58 -
( V_61 * V_55 ) ;
} else {
V_55 = 0 ;
V_56 = 0 ;
}
V_57 = V_54 -> V_57 [ V_55 ] >> V_56 ;
for (; ; ) {
if ( V_57 != 0 ) {
while ( ( V_57 & V_62 ) == 0 ) {
V_57 >>= 1 ;
V_56 ++ ;
}
return V_54 -> V_58 +
( V_61 * V_55 ) + V_56 ;
}
if ( ++ V_55 >= V_63 ) {
if ( V_54 -> V_60 != NULL ) {
V_54 = V_54 -> V_60 ;
V_55 = 0 ;
} else
return - V_47 ;
}
V_57 = V_54 -> V_57 [ V_55 ] ;
V_56 = 0 ;
}
return - V_47 ;
}
int F_24 ( struct V_51 * V_52 ,
T_2 V_53 )
{
struct V_51 * V_54 = V_52 ;
T_2 V_55 ;
T_2 V_56 ;
T_3 V_64 ;
T_3 V_57 ;
if ( V_53 > V_54 -> V_58 ) {
while ( V_53 >= ( V_54 -> V_58 + V_59 ) ) {
V_54 = V_54 -> V_60 ;
if ( V_54 == NULL )
return - V_47 ;
}
V_55 = ( V_53 - V_54 -> V_58 ) / V_61 ;
V_56 = V_53 - V_54 -> V_58 -
( V_61 * V_55 ) ;
} else {
V_55 = 0 ;
V_56 = 0 ;
}
V_64 = V_62 << V_56 ;
for (; ; ) {
V_57 = V_54 -> V_57 [ V_55 ] ;
while ( V_64 != 0 && ( V_57 & V_64 ) != 0 ) {
V_64 <<= 1 ;
V_56 ++ ;
}
if ( V_64 != 0 )
return V_54 -> V_58 +
( V_61 * V_55 ) +
V_56 - 1 ;
else if ( ++ V_55 >= V_63 ) {
if ( V_54 -> V_60 == NULL )
return V_54 -> V_58 + V_59 - 1 ;
V_54 = V_54 -> V_60 ;
V_55 = 0 ;
}
V_64 = V_62 ;
V_56 = 0 ;
}
return - V_47 ;
}
int F_25 ( struct V_51 * V_52 ,
T_2 V_65 ,
T_4 V_66 )
{
struct V_51 * V_54 = V_52 ;
T_2 V_56 ;
T_2 V_55 ;
while ( V_54 -> V_60 != NULL &&
V_65 >= ( V_54 -> V_58 + V_59 ) )
V_54 = V_54 -> V_60 ;
if ( V_65 >= ( V_54 -> V_58 + V_59 ) ) {
V_54 -> V_60 = F_26 ( V_66 ) ;
if ( V_54 -> V_60 == NULL )
return - V_11 ;
V_54 = V_54 -> V_60 ;
V_54 -> V_58 = V_65 & ~ ( V_59 - 1 ) ;
}
V_55 = ( V_65 - V_54 -> V_58 ) / V_61 ;
V_56 = V_65 - V_54 -> V_58 - ( V_61 * V_55 ) ;
V_54 -> V_57 [ V_55 ] |= V_62 << V_56 ;
return 0 ;
}
int F_27 ( struct V_51 * V_52 ,
T_2 V_67 ,
T_2 V_68 ,
T_4 V_66 )
{
int V_10 = 0 ;
struct V_51 * V_54 = V_52 ;
T_2 V_69 ;
T_2 V_70 ;
while ( V_54 -> V_60 != NULL &&
V_67 >= ( V_54 -> V_58 + V_59 ) )
V_54 = V_54 -> V_60 ;
V_69 = V_54 -> V_58 + V_59 ;
for ( V_70 = V_67 ; V_70 <= V_68 && V_10 == 0 ; V_70 ++ ) {
if ( V_70 >= V_69 && V_54 -> V_60 != NULL ) {
V_54 = V_54 -> V_60 ;
V_69 = V_54 -> V_58 + V_59 ;
}
V_10 = F_25 ( V_54 , V_70 , V_26 ) ;
}
return V_10 ;
}
int F_28 ( void )
{
return ( F_29 ( & V_71 ) > 0 ) ;
}
int F_30 ( struct V_72 * V_73 ,
T_1 V_2 ,
const struct V_74 * V_75 )
{
int V_10 ;
struct V_12 * V_76 ;
F_31 () ;
V_76 = F_32 ( V_75 -> V_1 ) ;
if ( V_76 == NULL ) {
V_10 = - V_47 ;
goto V_77;
}
switch ( V_2 ) {
case V_7 :
switch ( V_76 -> type ) {
case V_38 :
V_10 = - V_78 ;
break;
case V_50 :
V_10 = F_33 ( V_73 ,
V_76 -> V_36 . V_49 ,
V_75 ) ;
break;
case V_28 :
V_10 = 0 ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_79 ) || F_34 ( V_80 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_81 ;
}
V_77:
F_35 () ;
return V_10 ;
}
void F_36 ( struct V_72 * V_73 )
{
F_37 ( V_73 ) ;
}
int F_38 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
int V_10 ;
switch ( V_73 -> V_82 ) {
case V_7 :
V_10 = F_39 ( V_73 , V_75 ) ;
break;
#if F_34 ( V_79 ) || F_34 ( V_80 )
case V_34 :
V_10 = - V_83 ;
break;
#endif
default:
V_10 = - V_81 ;
}
return V_10 ;
}
int F_40 ( struct V_72 * V_73 ,
struct V_84 * V_3 ,
const struct V_74 * V_75 )
{
int V_10 ;
struct V_85 * V_21 ;
struct V_16 * V_86 ;
F_31 () ;
switch ( V_3 -> V_87 ) {
case V_7 :
V_21 = (struct V_85 * ) V_3 ;
V_86 = F_41 ( V_75 -> V_1 ,
V_21 -> V_88 . V_32 ) ;
if ( V_86 == NULL ) {
V_10 = - V_47 ;
goto V_89;
}
switch ( V_86 -> type ) {
case V_50 :
V_10 = F_33 ( V_73 ,
V_86 -> V_36 . V_49 ,
V_75 ) ;
break;
case V_28 :
F_37 ( V_73 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_79 ) || F_34 ( V_80 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_81 ;
}
V_89:
F_35 () ;
return V_10 ;
}
int F_42 ( struct V_90 * V_91 ,
const struct V_74 * V_75 )
{
int V_10 ;
struct V_12 * V_76 ;
struct V_16 * V_86 ;
T_2 V_92 ;
struct V_43 * V_93 ;
F_31 () ;
V_76 = F_32 ( V_75 -> V_1 ) ;
if ( V_76 == NULL ) {
V_10 = - V_47 ;
goto V_94;
}
switch ( V_91 -> V_95 -> V_2 ) {
case V_7 :
if ( V_76 -> type == V_38 ) {
struct V_96 * V_97 = F_43 ( V_91 ) ;
V_86 = F_41 ( V_75 -> V_1 ,
V_97 -> V_98 ) ;
if ( V_86 == NULL ) {
V_10 = - V_47 ;
goto V_94;
}
V_92 = V_86 -> type ;
V_93 = V_86 -> V_36 . V_49 ;
} else {
V_92 = V_76 -> type ;
V_93 = V_76 -> V_36 . V_49 ;
}
switch ( V_92 ) {
case V_50 :
V_10 = F_44 ( V_91 , V_93 , V_75 ) ;
break;
case V_28 :
F_45 ( V_91 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_79 ) || F_34 ( V_80 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_81 ;
}
V_94:
F_35 () ;
return V_10 ;
}
void F_46 ( struct V_90 * V_91 )
{
F_45 ( V_91 ) ;
}
int F_47 ( struct V_99 * V_100 ,
T_1 V_2 ,
const struct V_74 * V_75 )
{
int V_10 ;
struct V_101 * V_102 ;
struct V_16 * V_86 ;
F_31 () ;
switch ( V_2 ) {
case V_7 :
V_102 = F_48 ( V_100 ) ;
V_86 = F_41 ( V_75 -> V_1 ,
V_102 -> V_103 ) ;
if ( V_86 == NULL ) {
V_10 = - V_47 ;
goto V_104;
}
switch ( V_86 -> type ) {
case V_50 :
V_10 = F_49 ( V_100 ,
V_86 -> V_36 . V_49 ,
V_75 ) ;
break;
case V_28 :
V_10 = F_50 ( V_100 ) ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_79 ) || F_34 ( V_80 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_81 ;
}
V_104:
F_35 () ;
return V_10 ;
}
int F_51 ( const struct V_99 * V_100 ,
T_1 V_2 ,
struct V_74 * V_75 )
{
switch ( V_2 ) {
case V_7 :
if ( F_52 ( V_100 ) &&
F_53 ( V_100 , V_75 ) == 0 )
return 0 ;
break;
#if F_34 ( V_79 ) || F_34 ( V_80 )
case V_34 :
break;
#endif
}
return F_54 ( V_100 , V_2 , V_75 ) ;
}
void F_55 ( struct V_99 * V_100 , int error , int V_105 )
{
if ( F_52 ( V_100 ) )
F_56 ( V_100 , error , V_105 ) ;
}
void F_57 ( void )
{
F_58 () ;
}
int F_59 ( const struct V_99 * V_100 ,
const struct V_74 * V_75 )
{
if ( ( V_75 -> V_66 & V_106 ) == 0 )
return - V_83 ;
if ( F_52 ( V_100 ) )
return F_60 ( V_100 , V_75 ) ;
return - V_83 ;
}
struct V_107 * F_61 ( int type ,
struct V_5 * V_6 )
{
return F_62 ( type , V_6 ) ;
}
static int T_5 F_63 ( void )
{
int V_10 ;
F_64 ( V_108 L_1 ) ;
F_64 ( V_108 L_2 ,
( 1 << V_109 ) ) ;
F_64 ( V_108 L_3
L_4
L_5
L_6 ) ;
V_10 = F_65 ( V_109 ) ;
if ( V_10 != 0 )
goto V_110;
V_10 = F_66 ( V_111 ) ;
if ( V_10 != 0 )
goto V_110;
V_10 = F_67 () ;
if ( V_10 != 0 )
goto V_110;
V_10 = F_68 () ;
if ( V_10 != 0 )
goto V_110;
F_64 ( V_108 L_7 ) ;
return 0 ;
V_110:
F_69 ( L_8 , V_10 ) ;
}
