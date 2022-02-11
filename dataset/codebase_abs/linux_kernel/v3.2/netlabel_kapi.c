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
V_13 = F_5 ( sizeof( * V_13 ) , V_20 ) ;
if ( V_13 == NULL )
return - V_11 ;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_20 ) ;
if ( V_13 -> V_1 == NULL )
goto V_21;
}
if ( V_3 == NULL && V_4 == NULL )
V_13 -> type = V_22 ;
else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_20 ) ;
if ( V_15 == NULL )
goto V_21;
F_7 ( & V_15 -> V_23 ) ;
F_7 ( & V_15 -> V_24 ) ;
switch ( V_2 ) {
case V_7 : {
const struct V_25 * V_26 = V_3 ;
const struct V_25 * V_27 = V_4 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_20 ) ;
if ( V_17 == NULL )
goto V_21;
V_17 -> type = V_22 ;
V_17 -> V_28 . V_3 = V_26 -> V_29 & V_27 -> V_29 ;
V_17 -> V_28 . V_4 = V_27 -> V_29 ;
V_17 -> V_28 . V_30 = 1 ;
V_10 = F_8 ( & V_17 -> V_28 ,
& V_15 -> V_23 ) ;
if ( V_10 != 0 )
goto V_21;
break;
}
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 : {
const struct V_34 * V_35 = V_3 ;
const struct V_34 * V_36 = V_4 ;
V_19 = F_5 ( sizeof( * V_19 ) , V_20 ) ;
if ( V_19 == NULL )
goto V_21;
V_19 -> type = V_22 ;
F_10 ( & V_19 -> V_28 . V_3 , V_35 ) ;
V_19 -> V_28 . V_3 . V_37 [ 0 ] &= V_36 -> V_37 [ 0 ] ;
V_19 -> V_28 . V_3 . V_37 [ 1 ] &= V_36 -> V_37 [ 1 ] ;
V_19 -> V_28 . V_3 . V_37 [ 2 ] &= V_36 -> V_37 [ 2 ] ;
V_19 -> V_28 . V_3 . V_37 [ 3 ] &= V_36 -> V_37 [ 3 ] ;
F_10 ( & V_19 -> V_28 . V_4 , V_36 ) ;
V_19 -> V_28 . V_30 = 1 ;
V_10 = F_11 ( & V_19 -> V_28 ,
& V_15 -> V_24 ) ;
if ( V_10 != 0 )
goto V_21;
break;
}
#endif
default:
goto V_21;
break;
}
V_13 -> V_38 . V_39 = V_15 ;
V_13 -> type = V_40 ;
} else {
V_10 = - V_9 ;
goto V_21;
}
V_10 = F_12 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_21;
return 0 ;
V_21:
F_13 ( V_13 -> V_1 ) ;
F_13 ( V_13 ) ;
F_13 ( V_15 ) ;
F_13 ( V_17 ) ;
F_13 ( V_19 ) ;
return V_10 ;
}
int F_14 ( struct V_41 * V_41 ,
const char * V_42 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
T_2 V_43 ,
struct V_5 * V_6 )
{
T_2 V_44 ;
switch ( V_2 ) {
case V_7 :
V_44 = sizeof( struct V_25 ) ;
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
V_44 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_8 ;
}
return F_15 ( V_41 ,
V_42 , V_3 , V_4 , V_44 ,
V_43 , V_6 ) ;
}
int F_16 ( struct V_41 * V_41 ,
const char * V_42 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
struct V_5 * V_6 )
{
T_2 V_44 ;
switch ( V_2 ) {
case V_7 :
V_44 = sizeof( struct V_25 ) ;
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
V_44 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_8 ;
}
return F_17 ( V_41 ,
V_42 , V_3 , V_4 , V_44 ,
V_6 ) ;
}
int F_18 ( struct V_45 * V_46 ,
struct V_5 * V_6 )
{
return F_19 ( V_46 , V_6 ) ;
}
void F_20 ( T_2 V_47 , struct V_5 * V_6 )
{
F_21 ( V_47 , V_6 ) ;
}
int F_22 ( T_2 V_47 ,
const char * V_1 ,
const struct V_25 * V_3 ,
const struct V_25 * V_4 ,
struct V_5 * V_6 )
{
int V_10 = - V_11 ;
struct V_45 * V_46 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_48 = NULL ;
V_46 = F_23 ( V_47 ) ;
if ( V_46 == NULL )
return - V_49 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_20 ) ;
if ( V_13 == NULL )
goto V_50;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_20 ) ;
if ( V_13 -> V_1 == NULL )
goto V_51;
}
if ( V_3 == NULL && V_4 == NULL ) {
V_13 -> V_38 . V_52 = V_46 ;
V_13 -> type = V_53 ;
} else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_20 ) ;
if ( V_15 == NULL )
goto V_54;
F_7 ( & V_15 -> V_23 ) ;
F_7 ( & V_15 -> V_24 ) ;
V_48 = F_5 ( sizeof( * V_48 ) , V_20 ) ;
if ( V_48 == NULL )
goto V_55;
V_48 -> V_38 . V_52 = V_46 ;
V_48 -> type = V_53 ;
V_48 -> V_28 . V_3 = V_3 -> V_29 & V_4 -> V_29 ;
V_48 -> V_28 . V_4 = V_4 -> V_29 ;
V_48 -> V_28 . V_30 = 1 ;
V_10 = F_8 ( & V_48 -> V_28 , & V_15 -> V_23 ) ;
if ( V_10 != 0 )
goto V_56;
V_13 -> V_38 . V_39 = V_15 ;
V_13 -> type = V_40 ;
} else {
V_10 = - V_9 ;
goto V_54;
}
V_10 = F_12 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_56;
return 0 ;
V_56:
F_13 ( V_48 ) ;
V_55:
F_13 ( V_15 ) ;
V_54:
F_13 ( V_13 -> V_1 ) ;
V_51:
F_13 ( V_13 ) ;
V_50:
F_24 ( V_46 ) ;
return V_10 ;
}
int F_25 ( struct V_57 * V_58 ,
T_2 V_59 )
{
struct V_57 * V_60 = V_58 ;
T_2 V_61 ;
T_2 V_62 ;
T_3 V_63 ;
if ( V_59 > V_60 -> V_64 ) {
while ( V_59 >= ( V_60 -> V_64 + V_65 ) ) {
V_60 = V_60 -> V_66 ;
if ( V_60 == NULL )
return - V_49 ;
}
V_61 = ( V_59 - V_60 -> V_64 ) / V_67 ;
V_62 = V_59 - V_60 -> V_64 -
( V_67 * V_61 ) ;
} else {
V_61 = 0 ;
V_62 = 0 ;
}
V_63 = V_60 -> V_63 [ V_61 ] >> V_62 ;
for (; ; ) {
if ( V_63 != 0 ) {
while ( ( V_63 & V_68 ) == 0 ) {
V_63 >>= 1 ;
V_62 ++ ;
}
return V_60 -> V_64 +
( V_67 * V_61 ) + V_62 ;
}
if ( ++ V_61 >= V_69 ) {
if ( V_60 -> V_66 != NULL ) {
V_60 = V_60 -> V_66 ;
V_61 = 0 ;
} else
return - V_49 ;
}
V_63 = V_60 -> V_63 [ V_61 ] ;
V_62 = 0 ;
}
return - V_49 ;
}
int F_26 ( struct V_57 * V_58 ,
T_2 V_59 )
{
struct V_57 * V_60 = V_58 ;
T_2 V_61 ;
T_2 V_62 ;
T_3 V_70 ;
T_3 V_63 ;
if ( V_59 > V_60 -> V_64 ) {
while ( V_59 >= ( V_60 -> V_64 + V_65 ) ) {
V_60 = V_60 -> V_66 ;
if ( V_60 == NULL )
return - V_49 ;
}
V_61 = ( V_59 - V_60 -> V_64 ) / V_67 ;
V_62 = V_59 - V_60 -> V_64 -
( V_67 * V_61 ) ;
} else {
V_61 = 0 ;
V_62 = 0 ;
}
V_70 = V_68 << V_62 ;
for (; ; ) {
V_63 = V_60 -> V_63 [ V_61 ] ;
while ( V_70 != 0 && ( V_63 & V_70 ) != 0 ) {
V_70 <<= 1 ;
V_62 ++ ;
}
if ( V_70 != 0 )
return V_60 -> V_64 +
( V_67 * V_61 ) +
V_62 - 1 ;
else if ( ++ V_61 >= V_69 ) {
if ( V_60 -> V_66 == NULL )
return V_60 -> V_64 + V_65 - 1 ;
V_60 = V_60 -> V_66 ;
V_61 = 0 ;
}
V_70 = V_68 ;
V_62 = 0 ;
}
return - V_49 ;
}
int F_27 ( struct V_57 * V_58 ,
T_2 V_71 ,
T_4 V_72 )
{
struct V_57 * V_60 = V_58 ;
T_2 V_62 ;
T_2 V_61 ;
while ( V_60 -> V_66 != NULL &&
V_71 >= ( V_60 -> V_64 + V_65 ) )
V_60 = V_60 -> V_66 ;
if ( V_71 >= ( V_60 -> V_64 + V_65 ) ) {
V_60 -> V_66 = F_28 ( V_72 ) ;
if ( V_60 -> V_66 == NULL )
return - V_11 ;
V_60 = V_60 -> V_66 ;
V_60 -> V_64 = V_71 & ~ ( V_65 - 1 ) ;
}
V_61 = ( V_71 - V_60 -> V_64 ) / V_67 ;
V_62 = V_71 - V_60 -> V_64 - ( V_67 * V_61 ) ;
V_60 -> V_63 [ V_61 ] |= V_68 << V_62 ;
return 0 ;
}
int F_29 ( struct V_57 * V_58 ,
T_2 V_73 ,
T_2 V_74 ,
T_4 V_72 )
{
int V_10 = 0 ;
struct V_57 * V_60 = V_58 ;
T_2 V_75 ;
T_2 V_76 ;
while ( V_60 -> V_66 != NULL &&
V_73 >= ( V_60 -> V_64 + V_65 ) )
V_60 = V_60 -> V_66 ;
V_75 = V_60 -> V_64 + V_65 ;
for ( V_76 = V_73 ; V_76 <= V_74 && V_10 == 0 ; V_76 ++ ) {
if ( V_76 >= V_75 && V_60 -> V_66 != NULL ) {
V_60 = V_60 -> V_66 ;
V_75 = V_60 -> V_64 + V_65 ;
}
V_10 = F_27 ( V_60 , V_76 , V_20 ) ;
}
return V_10 ;
}
int F_30 ( void )
{
return ( F_31 ( & V_77 ) > 0 ) ;
}
int F_32 ( struct V_78 * V_79 ,
T_1 V_2 ,
const struct V_80 * V_81 )
{
int V_10 ;
struct V_12 * V_82 ;
F_33 () ;
V_82 = F_34 ( V_81 -> V_1 ) ;
if ( V_82 == NULL ) {
V_10 = - V_49 ;
goto V_83;
}
switch ( V_2 ) {
case V_7 :
switch ( V_82 -> type ) {
case V_40 :
V_10 = - V_84 ;
break;
case V_53 :
V_10 = F_35 ( V_79 ,
V_82 -> V_38 . V_52 ,
V_81 ) ;
break;
case V_22 :
V_10 = 0 ;
break;
default:
V_10 = - V_49 ;
}
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_83:
F_36 () ;
return V_10 ;
}
void F_37 ( struct V_78 * V_79 )
{
F_38 ( V_79 ) ;
}
int F_39 ( struct V_78 * V_79 ,
struct V_80 * V_81 )
{
int V_10 ;
switch ( V_79 -> V_86 ) {
case V_7 :
V_10 = F_40 ( V_79 , V_81 ) ;
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
V_10 = - V_87 ;
break;
#endif
default:
V_10 = - V_85 ;
}
return V_10 ;
}
int F_41 ( struct V_78 * V_79 ,
struct V_88 * V_3 ,
const struct V_80 * V_81 )
{
int V_10 ;
struct V_89 * V_26 ;
struct V_16 * V_90 ;
F_33 () ;
switch ( V_3 -> V_91 ) {
case V_7 :
V_26 = (struct V_89 * ) V_3 ;
V_90 = F_42 ( V_81 -> V_1 ,
V_26 -> V_92 . V_29 ) ;
if ( V_90 == NULL ) {
V_10 = - V_49 ;
goto V_93;
}
switch ( V_90 -> type ) {
case V_53 :
V_10 = F_35 ( V_79 ,
V_90 -> V_38 . V_52 ,
V_81 ) ;
break;
case V_22 :
F_38 ( V_79 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_49 ;
}
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_93:
F_36 () ;
return V_10 ;
}
int F_43 ( struct V_94 * V_95 ,
const struct V_80 * V_81 )
{
int V_10 ;
struct V_12 * V_82 ;
struct V_16 * V_90 ;
T_2 V_96 ;
struct V_45 * V_97 ;
F_33 () ;
V_82 = F_34 ( V_81 -> V_1 ) ;
if ( V_82 == NULL ) {
V_10 = - V_49 ;
goto V_98;
}
switch ( V_95 -> V_99 -> V_2 ) {
case V_7 :
if ( V_82 -> type == V_40 ) {
struct V_100 * V_101 = F_44 ( V_95 ) ;
V_90 = F_42 ( V_81 -> V_1 ,
V_101 -> V_102 ) ;
if ( V_90 == NULL ) {
V_10 = - V_49 ;
goto V_98;
}
V_96 = V_90 -> type ;
V_97 = V_90 -> V_38 . V_52 ;
} else {
V_96 = V_82 -> type ;
V_97 = V_82 -> V_38 . V_52 ;
}
switch ( V_96 ) {
case V_53 :
V_10 = F_45 ( V_95 , V_97 , V_81 ) ;
break;
case V_22 :
F_46 ( V_95 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_49 ;
}
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_98:
F_36 () ;
return V_10 ;
}
void F_47 ( struct V_94 * V_95 )
{
F_46 ( V_95 ) ;
}
int F_48 ( struct V_103 * V_104 ,
T_1 V_2 ,
const struct V_80 * V_81 )
{
int V_10 ;
struct V_105 * V_106 ;
struct V_16 * V_90 ;
F_33 () ;
switch ( V_2 ) {
case V_7 :
V_106 = F_49 ( V_104 ) ;
V_90 = F_42 ( V_81 -> V_1 ,
V_106 -> V_107 ) ;
if ( V_90 == NULL ) {
V_10 = - V_49 ;
goto V_108;
}
switch ( V_90 -> type ) {
case V_53 :
V_10 = F_50 ( V_104 ,
V_90 -> V_38 . V_52 ,
V_81 ) ;
break;
case V_22 :
V_10 = F_51 ( V_104 ) ;
break;
default:
V_10 = - V_49 ;
}
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_108:
F_36 () ;
return V_10 ;
}
int F_52 ( const struct V_103 * V_104 ,
T_1 V_2 ,
struct V_80 * V_81 )
{
switch ( V_2 ) {
case V_7 :
if ( F_53 ( V_104 ) &&
F_54 ( V_104 , V_81 ) == 0 )
return 0 ;
break;
#if F_9 ( V_31 ) || F_9 ( V_32 )
case V_33 :
break;
#endif
}
return F_55 ( V_104 , V_2 , V_81 ) ;
}
void F_56 ( struct V_103 * V_104 , int error , int V_109 )
{
if ( F_53 ( V_104 ) )
F_57 ( V_104 , error , V_109 ) ;
}
void F_58 ( void )
{
F_59 () ;
}
int F_60 ( const struct V_103 * V_104 ,
const struct V_80 * V_81 )
{
if ( ( V_81 -> V_72 & V_110 ) == 0 )
return - V_87 ;
if ( F_53 ( V_104 ) )
return F_61 ( V_104 , V_81 ) ;
return - V_87 ;
}
struct V_111 * F_62 ( int type ,
struct V_5 * V_6 )
{
return F_63 ( type , V_6 ) ;
}
static int T_5 F_64 ( void )
{
int V_10 ;
F_65 ( V_112 L_1 ) ;
F_65 ( V_112 L_2 ,
( 1 << V_113 ) ) ;
F_65 ( V_112 L_3
L_4
L_5
L_6 ) ;
V_10 = F_66 ( V_113 ) ;
if ( V_10 != 0 )
goto V_114;
V_10 = F_67 ( V_115 ) ;
if ( V_10 != 0 )
goto V_114;
V_10 = F_68 () ;
if ( V_10 != 0 )
goto V_114;
V_10 = F_69 () ;
if ( V_10 != 0 )
goto V_114;
F_65 ( V_112 L_7 ) ;
return 0 ;
V_114:
F_70 ( L_8 , V_10 ) ;
}
