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
V_13 -> V_22 . type = V_23 ;
else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_20 ) ;
if ( V_15 == NULL )
goto V_21;
F_7 ( & V_15 -> V_24 ) ;
F_7 ( & V_15 -> V_25 ) ;
switch ( V_2 ) {
case V_7 : {
const struct V_26 * V_27 = V_3 ;
const struct V_26 * V_28 = V_4 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_20 ) ;
if ( V_17 == NULL )
goto V_21;
V_17 -> V_22 . type = V_23 ;
V_17 -> V_29 . V_3 = V_27 -> V_30 & V_28 -> V_30 ;
V_17 -> V_29 . V_4 = V_28 -> V_30 ;
V_17 -> V_29 . V_31 = 1 ;
V_10 = F_8 ( & V_17 -> V_29 ,
& V_15 -> V_24 ) ;
if ( V_10 != 0 )
goto V_21;
break;
}
#if F_9 ( V_32 )
case V_33 : {
const struct V_34 * V_35 = V_3 ;
const struct V_34 * V_36 = V_4 ;
V_19 = F_5 ( sizeof( * V_19 ) , V_20 ) ;
if ( V_19 == NULL )
goto V_21;
V_19 -> V_22 . type = V_23 ;
V_19 -> V_29 . V_3 = * V_35 ;
V_19 -> V_29 . V_3 . V_37 [ 0 ] &= V_36 -> V_37 [ 0 ] ;
V_19 -> V_29 . V_3 . V_37 [ 1 ] &= V_36 -> V_37 [ 1 ] ;
V_19 -> V_29 . V_3 . V_37 [ 2 ] &= V_36 -> V_37 [ 2 ] ;
V_19 -> V_29 . V_3 . V_37 [ 3 ] &= V_36 -> V_37 [ 3 ] ;
V_19 -> V_29 . V_4 = * V_36 ;
V_19 -> V_29 . V_31 = 1 ;
V_10 = F_10 ( & V_19 -> V_29 ,
& V_15 -> V_25 ) ;
if ( V_10 != 0 )
goto V_21;
break;
}
#endif
default:
goto V_21;
}
V_13 -> V_22 . V_38 = V_15 ;
V_13 -> V_22 . type = V_39 ;
} else {
V_10 = - V_9 ;
goto V_21;
}
V_10 = F_11 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_21;
return 0 ;
V_21:
F_12 ( V_13 -> V_1 ) ;
F_12 ( V_13 ) ;
F_12 ( V_15 ) ;
F_12 ( V_17 ) ;
F_12 ( V_19 ) ;
return V_10 ;
}
int F_13 ( struct V_40 * V_40 ,
const char * V_41 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
T_2 V_42 ,
struct V_5 * V_6 )
{
T_2 V_43 ;
switch ( V_2 ) {
case V_7 :
V_43 = sizeof( struct V_26 ) ;
break;
#if F_9 ( V_32 )
case V_33 :
V_43 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_8 ;
}
return F_14 ( V_40 ,
V_41 , V_3 , V_4 , V_43 ,
V_42 , V_6 ) ;
}
int F_15 ( struct V_40 * V_40 ,
const char * V_41 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
struct V_5 * V_6 )
{
T_2 V_43 ;
switch ( V_2 ) {
case V_7 :
V_43 = sizeof( struct V_26 ) ;
break;
#if F_9 ( V_32 )
case V_33 :
V_43 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_8 ;
}
return F_16 ( V_40 ,
V_41 , V_3 , V_4 , V_43 ,
V_6 ) ;
}
int F_17 ( struct V_44 * V_45 ,
struct V_5 * V_6 )
{
return F_18 ( V_45 , V_6 ) ;
}
void F_19 ( T_2 V_46 , struct V_5 * V_6 )
{
F_20 ( V_46 , V_6 ) ;
}
int F_21 ( T_2 V_46 ,
const char * V_1 ,
const struct V_26 * V_3 ,
const struct V_26 * V_4 ,
struct V_5 * V_6 )
{
int V_10 = - V_11 ;
struct V_44 * V_45 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_47 = NULL ;
V_45 = F_22 ( V_46 ) ;
if ( V_45 == NULL )
return - V_48 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_20 ) ;
if ( V_13 == NULL )
goto V_49;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_20 ) ;
if ( V_13 -> V_1 == NULL )
goto V_50;
}
if ( V_3 == NULL && V_4 == NULL ) {
V_13 -> V_22 . V_51 = V_45 ;
V_13 -> V_22 . type = V_52 ;
} else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_20 ) ;
if ( V_15 == NULL )
goto V_53;
F_7 ( & V_15 -> V_24 ) ;
F_7 ( & V_15 -> V_25 ) ;
V_47 = F_5 ( sizeof( * V_47 ) , V_20 ) ;
if ( V_47 == NULL )
goto V_54;
V_47 -> V_22 . V_51 = V_45 ;
V_47 -> V_22 . type = V_52 ;
V_47 -> V_29 . V_3 = V_3 -> V_30 & V_4 -> V_30 ;
V_47 -> V_29 . V_4 = V_4 -> V_30 ;
V_47 -> V_29 . V_31 = 1 ;
V_10 = F_8 ( & V_47 -> V_29 , & V_15 -> V_24 ) ;
if ( V_10 != 0 )
goto V_55;
V_13 -> V_22 . V_38 = V_15 ;
V_13 -> V_22 . type = V_39 ;
} else {
V_10 = - V_9 ;
goto V_53;
}
V_10 = F_11 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_55;
return 0 ;
V_55:
F_12 ( V_47 ) ;
V_54:
F_12 ( V_15 ) ;
V_53:
F_12 ( V_13 -> V_1 ) ;
V_50:
F_12 ( V_13 ) ;
V_49:
F_23 ( V_45 ) ;
return V_10 ;
}
static struct V_56 * F_24 (
struct V_56 * * V_57 ,
T_2 V_58 ,
unsigned int V_59 ,
T_3 V_60 )
{
struct V_56 * V_61 = * V_57 ;
struct V_56 * V_62 = NULL ;
if ( V_61 == NULL )
goto V_63;
if ( V_58 < V_61 -> V_64 )
goto V_65;
while ( V_61 && V_58 >= ( V_61 -> V_64 + V_66 ) ) {
V_62 = V_61 ;
V_61 = V_61 -> V_67 ;
}
if ( V_61 == NULL || V_58 < V_61 -> V_64 )
goto V_65;
return V_61 ;
V_65:
if ( V_59 & V_68 )
return V_61 ;
V_63:
if ( ! ( V_59 & V_69 ) )
return NULL ;
V_61 = F_25 ( V_60 ) ;
if ( V_61 == NULL )
return NULL ;
V_61 -> V_64 = V_58 & ~ ( V_66 - 1 ) ;
if ( V_62 == NULL ) {
V_61 -> V_67 = * V_57 ;
* V_57 = V_61 ;
} else {
V_61 -> V_67 = V_62 -> V_67 ;
V_62 -> V_67 = V_61 ;
}
return V_61 ;
}
int F_26 ( struct V_56 * V_57 , T_2 V_58 )
{
struct V_56 * V_61 = V_57 ;
T_2 V_70 ;
T_2 V_71 ;
T_4 V_72 ;
V_61 = F_24 ( & V_57 , V_58 , V_68 , 0 ) ;
if ( V_61 == NULL )
return - V_48 ;
if ( V_58 > V_61 -> V_64 ) {
V_58 -= V_61 -> V_64 ;
V_70 = V_58 / V_73 ;
V_71 = V_58 % V_73 ;
} else {
V_70 = 0 ;
V_71 = 0 ;
}
V_72 = V_61 -> V_72 [ V_70 ] >> V_71 ;
for (; ; ) {
if ( V_72 != 0 ) {
while ( ( V_72 & V_74 ) == 0 ) {
V_72 >>= 1 ;
V_71 ++ ;
}
return V_61 -> V_64 +
( V_73 * V_70 ) + V_71 ;
}
if ( ++ V_70 >= V_75 ) {
if ( V_61 -> V_67 != NULL ) {
V_61 = V_61 -> V_67 ;
V_70 = 0 ;
} else
return - V_48 ;
}
V_72 = V_61 -> V_72 [ V_70 ] ;
V_71 = 0 ;
}
return - V_48 ;
}
int F_27 ( struct V_56 * V_57 , T_2 V_58 )
{
struct V_56 * V_61 ;
struct V_56 * V_62 = NULL ;
T_2 V_70 ;
T_2 V_71 ;
T_4 V_76 ;
T_4 V_72 ;
V_61 = F_24 ( & V_57 , V_58 , V_68 , 0 ) ;
if ( V_61 == NULL )
return - V_48 ;
if ( V_58 > V_61 -> V_64 ) {
V_58 -= V_61 -> V_64 ;
V_70 = V_58 / V_73 ;
V_71 = V_58 % V_73 ;
} else {
V_70 = 0 ;
V_71 = 0 ;
}
V_76 = V_74 << V_71 ;
for (; ; ) {
V_72 = V_61 -> V_72 [ V_70 ] ;
while ( V_76 != 0 && ( V_72 & V_76 ) != 0 ) {
V_76 <<= 1 ;
V_71 ++ ;
}
if ( V_62 && V_70 == 0 && V_71 == 0 )
return V_62 -> V_64 + V_66 - 1 ;
else if ( V_76 != 0 )
return V_61 -> V_64 +
( V_73 * V_70 ) + V_71 - 1 ;
else if ( ++ V_70 >= V_75 ) {
if ( V_61 -> V_67 == NULL )
return V_61 -> V_64 + V_66 - 1 ;
V_62 = V_61 ;
V_61 = V_61 -> V_67 ;
V_70 = 0 ;
}
V_76 = V_74 ;
V_71 = 0 ;
}
return - V_48 ;
}
int F_28 ( struct V_56 * V_57 ,
T_2 * V_58 ,
unsigned long * V_72 )
{
struct V_56 * V_61 ;
T_2 V_77 = * V_58 ;
T_2 V_70 ;
if ( ( V_77 & ( V_78 - 1 ) ) != 0 )
return - V_9 ;
if ( V_77 < V_57 -> V_64 ) {
V_77 = V_57 -> V_64 ;
* V_58 = V_77 ;
}
V_61 = F_24 ( & V_57 , V_77 , V_79 , 0 ) ;
if ( V_61 == NULL ) {
* V_58 = ( T_2 ) - 1 ;
return 0 ;
}
if ( V_77 < V_61 -> V_64 ) {
V_77 = V_61 -> V_64 ;
* V_58 = V_77 ;
} else
V_77 -= V_61 -> V_64 ;
V_70 = V_77 / V_73 ;
* V_72 = V_61 -> V_72 [ V_70 ] >> ( V_77 % V_66 ) ;
return 0 ;
}
int F_29 ( struct V_56 * * V_57 ,
T_2 V_71 ,
T_3 V_80 )
{
struct V_56 * V_61 ;
T_2 V_70 ;
V_61 = F_24 ( V_57 , V_71 , V_69 , V_80 ) ;
if ( V_61 == NULL )
return - V_11 ;
V_71 -= V_61 -> V_64 ;
V_70 = V_71 / V_73 ;
V_61 -> V_72 [ V_70 ] |= V_74 << ( V_71 % V_73 ) ;
return 0 ;
}
int F_30 ( struct V_56 * * V_57 ,
T_2 V_81 ,
T_2 V_82 ,
T_3 V_80 )
{
int V_83 = 0 ;
T_2 V_84 = V_81 ;
while ( V_83 == 0 && V_84 <= V_82 ) {
if ( ( ( V_84 & ( V_78 - 1 ) ) == 0 ) &&
( ( V_82 - V_84 ) > V_78 ) ) {
V_83 = F_31 ( V_57 ,
V_84 ,
( unsigned long ) - 1 ,
V_80 ) ;
V_84 += V_78 ;
} else
V_83 = F_29 ( V_57 , V_84 ++ , V_80 ) ;
}
return V_83 ;
}
int F_31 ( struct V_56 * * V_57 ,
T_2 V_58 ,
unsigned long V_72 ,
T_3 V_80 )
{
struct V_56 * V_61 ;
T_2 V_70 ;
if ( ( V_58 & ( V_78 - 1 ) ) != 0 )
return - V_9 ;
V_61 = F_24 ( V_57 , V_58 , V_69 , V_80 ) ;
if ( V_61 == NULL )
return - V_11 ;
V_58 -= V_61 -> V_64 ;
V_70 = V_58 / V_73 ;
V_61 -> V_72 [ V_70 ] |= V_72 << ( V_58 % V_73 ) ;
return 0 ;
}
int F_32 ( void )
{
return ( F_33 ( & V_85 ) > 0 ) ;
}
int F_34 ( struct V_86 * V_87 ,
T_1 V_2 ,
const struct V_88 * V_89 )
{
int V_10 ;
struct V_12 * V_90 ;
F_35 () ;
V_90 = F_36 ( V_89 -> V_1 ) ;
if ( V_90 == NULL ) {
V_10 = - V_48 ;
goto V_91;
}
switch ( V_2 ) {
case V_7 :
switch ( V_90 -> V_22 . type ) {
case V_39 :
V_10 = - V_92 ;
break;
case V_52 :
V_10 = F_37 ( V_87 ,
V_90 -> V_22 . V_51 ,
V_89 ) ;
break;
case V_23 :
V_10 = 0 ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_93 ;
}
V_91:
F_38 () ;
return V_10 ;
}
void F_39 ( struct V_86 * V_87 )
{
F_40 ( V_87 ) ;
}
int F_41 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
int V_10 ;
switch ( V_87 -> V_94 ) {
case V_7 :
V_10 = F_42 ( V_87 , V_89 ) ;
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = - V_95 ;
break;
#endif
default:
V_10 = - V_93 ;
}
return V_10 ;
}
int F_43 ( struct V_86 * V_87 ,
struct V_96 * V_3 ,
const struct V_88 * V_89 )
{
int V_10 ;
struct V_97 * V_27 ;
struct V_98 * V_13 ;
F_35 () ;
switch ( V_3 -> V_99 ) {
case V_7 :
V_27 = (struct V_97 * ) V_3 ;
V_13 = F_44 ( V_89 -> V_1 ,
V_27 -> V_100 . V_30 ) ;
if ( V_13 == NULL ) {
V_10 = - V_48 ;
goto V_101;
}
switch ( V_13 -> type ) {
case V_52 :
V_10 = F_37 ( V_87 ,
V_13 -> V_51 , V_89 ) ;
break;
case V_23 :
F_40 ( V_87 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_93 ;
}
V_101:
F_38 () ;
return V_10 ;
}
int F_45 ( struct V_102 * V_103 ,
const struct V_88 * V_89 )
{
int V_10 ;
struct V_98 * V_13 ;
F_35 () ;
switch ( V_103 -> V_104 -> V_2 ) {
case V_7 :
V_13 = F_44 ( V_89 -> V_1 ,
F_46 ( V_103 ) -> V_105 ) ;
if ( V_13 == NULL ) {
V_10 = - V_48 ;
goto V_106;
}
switch ( V_13 -> type ) {
case V_52 :
V_10 = F_47 ( V_103 ,
V_13 -> V_51 , V_89 ) ;
break;
case V_23 :
F_48 ( V_103 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_93 ;
}
V_106:
F_38 () ;
return V_10 ;
}
void F_49 ( struct V_102 * V_103 )
{
F_48 ( V_103 ) ;
}
int F_50 ( struct V_107 * V_108 ,
T_1 V_2 ,
const struct V_88 * V_89 )
{
int V_10 ;
struct V_109 * V_110 ;
struct V_98 * V_13 ;
F_35 () ;
switch ( V_2 ) {
case V_7 :
V_110 = F_51 ( V_108 ) ;
V_13 = F_44 ( V_89 -> V_1 , V_110 -> V_111 ) ;
if ( V_13 == NULL ) {
V_10 = - V_48 ;
goto V_112;
}
switch ( V_13 -> type ) {
case V_52 :
V_10 = F_52 ( V_108 , V_13 -> V_51 ,
V_89 ) ;
break;
case V_23 :
V_10 = F_53 ( V_108 ) ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_93 ;
}
V_112:
F_38 () ;
return V_10 ;
}
int F_54 ( const struct V_107 * V_108 ,
T_1 V_2 ,
struct V_88 * V_89 )
{
unsigned char * V_113 ;
switch ( V_2 ) {
case V_7 :
V_113 = F_55 ( V_108 ) ;
if ( V_113 && F_56 ( V_113 , V_89 ) == 0 )
return 0 ;
break;
#if F_9 ( V_32 )
case V_33 :
break;
#endif
}
return F_57 ( V_108 , V_2 , V_89 ) ;
}
void F_58 ( struct V_107 * V_108 , int error , int V_114 )
{
if ( F_55 ( V_108 ) )
F_59 ( V_108 , error , V_114 ) ;
}
void F_60 ( void )
{
F_61 () ;
}
int F_62 ( const struct V_107 * V_108 ,
const struct V_88 * V_89 )
{
unsigned char * V_113 ;
if ( ( V_89 -> V_80 & V_115 ) == 0 )
return - V_95 ;
V_113 = F_55 ( V_108 ) ;
if ( V_113 )
return F_63 ( V_113 , V_89 ) ;
return - V_95 ;
}
struct V_116 * F_64 ( int type ,
struct V_5 * V_6 )
{
return F_65 ( type , V_6 ) ;
}
static int T_5 F_66 ( void )
{
int V_10 ;
F_67 ( V_117 L_1 ) ;
F_67 ( V_117 L_2 ,
( 1 << V_118 ) ) ;
F_67 ( V_117 L_3
L_4
L_5
L_6 ) ;
V_10 = F_68 ( V_118 ) ;
if ( V_10 != 0 )
goto V_119;
V_10 = F_69 ( V_120 ) ;
if ( V_10 != 0 )
goto V_119;
V_10 = F_70 () ;
if ( V_10 != 0 )
goto V_119;
V_10 = F_71 () ;
if ( V_10 != 0 )
goto V_119;
F_67 ( V_117 L_7 ) ;
return 0 ;
V_119:
F_72 ( L_8 , V_10 ) ;
}
