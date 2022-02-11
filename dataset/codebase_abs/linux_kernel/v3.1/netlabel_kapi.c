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
goto V_48;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_26 ) ;
if ( V_13 -> V_1 == NULL )
goto V_49;
}
if ( V_3 == NULL && V_4 == NULL ) {
V_13 -> V_36 . V_50 = V_44 ;
V_13 -> type = V_51 ;
} else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_26 ) ;
if ( V_15 == NULL )
goto V_52;
F_7 ( & V_15 -> V_29 ) ;
F_7 ( & V_15 -> V_30 ) ;
V_46 = F_5 ( sizeof( * V_46 ) , V_26 ) ;
if ( V_46 == NULL )
goto V_53;
V_46 -> V_36 . V_50 = V_44 ;
V_46 -> type = V_51 ;
V_46 -> V_31 . V_3 = V_3 -> V_32 & V_4 -> V_32 ;
V_46 -> V_31 . V_4 = V_4 -> V_32 ;
V_46 -> V_31 . V_33 = 1 ;
V_10 = F_8 ( & V_46 -> V_31 , & V_15 -> V_29 ) ;
if ( V_10 != 0 )
goto V_54;
V_13 -> V_36 . V_37 = V_15 ;
V_13 -> type = V_38 ;
} else {
V_10 = - V_9 ;
goto V_52;
}
V_10 = F_10 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_54;
return 0 ;
V_54:
F_11 ( V_46 ) ;
V_53:
F_11 ( V_15 ) ;
V_52:
F_11 ( V_13 -> V_1 ) ;
V_49:
F_11 ( V_13 ) ;
V_48:
F_22 ( V_44 ) ;
return V_10 ;
}
int F_23 ( struct V_55 * V_56 ,
T_2 V_57 )
{
struct V_55 * V_58 = V_56 ;
T_2 V_59 ;
T_2 V_60 ;
T_3 V_61 ;
if ( V_57 > V_58 -> V_62 ) {
while ( V_57 >= ( V_58 -> V_62 + V_63 ) ) {
V_58 = V_58 -> V_64 ;
if ( V_58 == NULL )
return - V_47 ;
}
V_59 = ( V_57 - V_58 -> V_62 ) / V_65 ;
V_60 = V_57 - V_58 -> V_62 -
( V_65 * V_59 ) ;
} else {
V_59 = 0 ;
V_60 = 0 ;
}
V_61 = V_58 -> V_61 [ V_59 ] >> V_60 ;
for (; ; ) {
if ( V_61 != 0 ) {
while ( ( V_61 & V_66 ) == 0 ) {
V_61 >>= 1 ;
V_60 ++ ;
}
return V_58 -> V_62 +
( V_65 * V_59 ) + V_60 ;
}
if ( ++ V_59 >= V_67 ) {
if ( V_58 -> V_64 != NULL ) {
V_58 = V_58 -> V_64 ;
V_59 = 0 ;
} else
return - V_47 ;
}
V_61 = V_58 -> V_61 [ V_59 ] ;
V_60 = 0 ;
}
return - V_47 ;
}
int F_24 ( struct V_55 * V_56 ,
T_2 V_57 )
{
struct V_55 * V_58 = V_56 ;
T_2 V_59 ;
T_2 V_60 ;
T_3 V_68 ;
T_3 V_61 ;
if ( V_57 > V_58 -> V_62 ) {
while ( V_57 >= ( V_58 -> V_62 + V_63 ) ) {
V_58 = V_58 -> V_64 ;
if ( V_58 == NULL )
return - V_47 ;
}
V_59 = ( V_57 - V_58 -> V_62 ) / V_65 ;
V_60 = V_57 - V_58 -> V_62 -
( V_65 * V_59 ) ;
} else {
V_59 = 0 ;
V_60 = 0 ;
}
V_68 = V_66 << V_60 ;
for (; ; ) {
V_61 = V_58 -> V_61 [ V_59 ] ;
while ( V_68 != 0 && ( V_61 & V_68 ) != 0 ) {
V_68 <<= 1 ;
V_60 ++ ;
}
if ( V_68 != 0 )
return V_58 -> V_62 +
( V_65 * V_59 ) +
V_60 - 1 ;
else if ( ++ V_59 >= V_67 ) {
if ( V_58 -> V_64 == NULL )
return V_58 -> V_62 + V_63 - 1 ;
V_58 = V_58 -> V_64 ;
V_59 = 0 ;
}
V_68 = V_66 ;
V_60 = 0 ;
}
return - V_47 ;
}
int F_25 ( struct V_55 * V_56 ,
T_2 V_69 ,
T_4 V_70 )
{
struct V_55 * V_58 = V_56 ;
T_2 V_60 ;
T_2 V_59 ;
while ( V_58 -> V_64 != NULL &&
V_69 >= ( V_58 -> V_62 + V_63 ) )
V_58 = V_58 -> V_64 ;
if ( V_69 >= ( V_58 -> V_62 + V_63 ) ) {
V_58 -> V_64 = F_26 ( V_70 ) ;
if ( V_58 -> V_64 == NULL )
return - V_11 ;
V_58 = V_58 -> V_64 ;
V_58 -> V_62 = V_69 & ~ ( V_63 - 1 ) ;
}
V_59 = ( V_69 - V_58 -> V_62 ) / V_65 ;
V_60 = V_69 - V_58 -> V_62 - ( V_65 * V_59 ) ;
V_58 -> V_61 [ V_59 ] |= V_66 << V_60 ;
return 0 ;
}
int F_27 ( struct V_55 * V_56 ,
T_2 V_71 ,
T_2 V_72 ,
T_4 V_70 )
{
int V_10 = 0 ;
struct V_55 * V_58 = V_56 ;
T_2 V_73 ;
T_2 V_74 ;
while ( V_58 -> V_64 != NULL &&
V_71 >= ( V_58 -> V_62 + V_63 ) )
V_58 = V_58 -> V_64 ;
V_73 = V_58 -> V_62 + V_63 ;
for ( V_74 = V_71 ; V_74 <= V_72 && V_10 == 0 ; V_74 ++ ) {
if ( V_74 >= V_73 && V_58 -> V_64 != NULL ) {
V_58 = V_58 -> V_64 ;
V_73 = V_58 -> V_62 + V_63 ;
}
V_10 = F_25 ( V_58 , V_74 , V_26 ) ;
}
return V_10 ;
}
int F_28 ( void )
{
return ( F_29 ( & V_75 ) > 0 ) ;
}
int F_30 ( struct V_76 * V_77 ,
T_1 V_2 ,
const struct V_78 * V_79 )
{
int V_10 ;
struct V_12 * V_80 ;
F_31 () ;
V_80 = F_32 ( V_79 -> V_1 ) ;
if ( V_80 == NULL ) {
V_10 = - V_47 ;
goto V_81;
}
switch ( V_2 ) {
case V_7 :
switch ( V_80 -> type ) {
case V_38 :
V_10 = - V_82 ;
break;
case V_51 :
V_10 = F_33 ( V_77 ,
V_80 -> V_36 . V_50 ,
V_79 ) ;
break;
case V_28 :
V_10 = 0 ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_83 ) || F_34 ( V_84 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_81:
F_35 () ;
return V_10 ;
}
void F_36 ( struct V_76 * V_77 )
{
F_37 ( V_77 ) ;
}
int F_38 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
int V_10 ;
switch ( V_77 -> V_86 ) {
case V_7 :
V_10 = F_39 ( V_77 , V_79 ) ;
break;
#if F_34 ( V_83 ) || F_34 ( V_84 )
case V_34 :
V_10 = - V_87 ;
break;
#endif
default:
V_10 = - V_85 ;
}
return V_10 ;
}
int F_40 ( struct V_76 * V_77 ,
struct V_88 * V_3 ,
const struct V_78 * V_79 )
{
int V_10 ;
struct V_89 * V_21 ;
struct V_16 * V_90 ;
F_31 () ;
switch ( V_3 -> V_91 ) {
case V_7 :
V_21 = (struct V_89 * ) V_3 ;
V_90 = F_41 ( V_79 -> V_1 ,
V_21 -> V_92 . V_32 ) ;
if ( V_90 == NULL ) {
V_10 = - V_47 ;
goto V_93;
}
switch ( V_90 -> type ) {
case V_51 :
V_10 = F_33 ( V_77 ,
V_90 -> V_36 . V_50 ,
V_79 ) ;
break;
case V_28 :
F_37 ( V_77 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_83 ) || F_34 ( V_84 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_93:
F_35 () ;
return V_10 ;
}
int F_42 ( struct V_94 * V_95 ,
const struct V_78 * V_79 )
{
int V_10 ;
struct V_12 * V_80 ;
struct V_16 * V_90 ;
T_2 V_96 ;
struct V_43 * V_97 ;
F_31 () ;
V_80 = F_32 ( V_79 -> V_1 ) ;
if ( V_80 == NULL ) {
V_10 = - V_47 ;
goto V_98;
}
switch ( V_95 -> V_99 -> V_2 ) {
case V_7 :
if ( V_80 -> type == V_38 ) {
struct V_100 * V_101 = F_43 ( V_95 ) ;
V_90 = F_41 ( V_79 -> V_1 ,
V_101 -> V_102 ) ;
if ( V_90 == NULL ) {
V_10 = - V_47 ;
goto V_98;
}
V_96 = V_90 -> type ;
V_97 = V_90 -> V_36 . V_50 ;
} else {
V_96 = V_80 -> type ;
V_97 = V_80 -> V_36 . V_50 ;
}
switch ( V_96 ) {
case V_51 :
V_10 = F_44 ( V_95 , V_97 , V_79 ) ;
break;
case V_28 :
F_45 ( V_95 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_83 ) || F_34 ( V_84 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_98:
F_35 () ;
return V_10 ;
}
void F_46 ( struct V_94 * V_95 )
{
F_45 ( V_95 ) ;
}
int F_47 ( struct V_103 * V_104 ,
T_1 V_2 ,
const struct V_78 * V_79 )
{
int V_10 ;
struct V_105 * V_106 ;
struct V_16 * V_90 ;
F_31 () ;
switch ( V_2 ) {
case V_7 :
V_106 = F_48 ( V_104 ) ;
V_90 = F_41 ( V_79 -> V_1 ,
V_106 -> V_107 ) ;
if ( V_90 == NULL ) {
V_10 = - V_47 ;
goto V_108;
}
switch ( V_90 -> type ) {
case V_51 :
V_10 = F_49 ( V_104 ,
V_90 -> V_36 . V_50 ,
V_79 ) ;
break;
case V_28 :
V_10 = F_50 ( V_104 ) ;
break;
default:
V_10 = - V_47 ;
}
break;
#if F_34 ( V_83 ) || F_34 ( V_84 )
case V_34 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_85 ;
}
V_108:
F_35 () ;
return V_10 ;
}
int F_51 ( const struct V_103 * V_104 ,
T_1 V_2 ,
struct V_78 * V_79 )
{
switch ( V_2 ) {
case V_7 :
if ( F_52 ( V_104 ) &&
F_53 ( V_104 , V_79 ) == 0 )
return 0 ;
break;
#if F_34 ( V_83 ) || F_34 ( V_84 )
case V_34 :
break;
#endif
}
return F_54 ( V_104 , V_2 , V_79 ) ;
}
void F_55 ( struct V_103 * V_104 , int error , int V_109 )
{
if ( F_52 ( V_104 ) )
F_56 ( V_104 , error , V_109 ) ;
}
void F_57 ( void )
{
F_58 () ;
}
int F_59 ( const struct V_103 * V_104 ,
const struct V_78 * V_79 )
{
if ( ( V_79 -> V_70 & V_110 ) == 0 )
return - V_87 ;
if ( F_52 ( V_104 ) )
return F_60 ( V_104 , V_79 ) ;
return - V_87 ;
}
struct V_111 * F_61 ( int type ,
struct V_5 * V_6 )
{
return F_62 ( type , V_6 ) ;
}
static int T_5 F_63 ( void )
{
int V_10 ;
F_64 ( V_112 L_1 ) ;
F_64 ( V_112 L_2 ,
( 1 << V_113 ) ) ;
F_64 ( V_112 L_3
L_4
L_5
L_6 ) ;
V_10 = F_65 ( V_113 ) ;
if ( V_10 != 0 )
goto V_114;
V_10 = F_66 ( V_115 ) ;
if ( V_10 != 0 )
goto V_114;
V_10 = F_67 () ;
if ( V_10 != 0 )
goto V_114;
V_10 = F_68 () ;
if ( V_10 != 0 )
goto V_114;
F_64 ( V_112 L_7 ) ;
return 0 ;
V_114:
F_69 ( L_8 , V_10 ) ;
}
