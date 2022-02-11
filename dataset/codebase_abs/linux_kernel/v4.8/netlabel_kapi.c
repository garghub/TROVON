int F_1 ( const char * V_1 ,
T_1 V_2 ,
const void * V_3 ,
const void * V_4 ,
struct V_5 * V_6 )
{
if ( V_3 == NULL && V_4 == NULL ) {
return F_2 ( V_1 , V_2 , V_6 ) ;
} else if ( V_3 != NULL && V_4 != NULL ) {
switch ( V_2 ) {
case V_7 :
return F_3 ( V_1 , V_3 , V_4 ,
V_6 ) ;
#if F_4 ( V_8 )
case V_9 :
return F_5 ( V_1 , V_3 , V_4 ,
V_6 ) ;
#endif
default:
return - V_10 ;
}
} else
return - V_11 ;
}
int F_6 ( const char * V_1 ,
T_1 V_2 ,
const void * V_3 ,
const void * V_4 ,
struct V_5 * V_6 )
{
int V_12 = - V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
V_15 = F_7 ( sizeof( * V_15 ) , V_22 ) ;
if ( V_15 == NULL )
return - V_13 ;
if ( V_1 != NULL ) {
V_15 -> V_1 = F_8 ( V_1 , V_22 ) ;
if ( V_15 -> V_1 == NULL )
goto V_23;
}
V_15 -> V_2 = V_2 ;
if ( V_3 == NULL && V_4 == NULL )
V_15 -> V_24 . type = V_25 ;
else if ( V_3 != NULL && V_4 != NULL ) {
V_17 = F_7 ( sizeof( * V_17 ) , V_22 ) ;
if ( V_17 == NULL )
goto V_23;
F_9 ( & V_17 -> V_26 ) ;
F_9 ( & V_17 -> V_27 ) ;
switch ( V_2 ) {
case V_7 : {
const struct V_28 * V_29 = V_3 ;
const struct V_28 * V_30 = V_4 ;
V_19 = F_7 ( sizeof( * V_19 ) , V_22 ) ;
if ( V_19 == NULL )
goto V_23;
V_19 -> V_24 . type = V_25 ;
V_19 -> V_31 . V_3 = V_29 -> V_32 & V_30 -> V_32 ;
V_19 -> V_31 . V_4 = V_30 -> V_32 ;
V_19 -> V_31 . V_33 = 1 ;
V_12 = F_10 ( & V_19 -> V_31 ,
& V_17 -> V_26 ) ;
if ( V_12 != 0 )
goto V_23;
break;
}
#if F_4 ( V_8 )
case V_9 : {
const struct V_34 * V_35 = V_3 ;
const struct V_34 * V_36 = V_4 ;
V_21 = F_7 ( sizeof( * V_21 ) , V_22 ) ;
if ( V_21 == NULL )
goto V_23;
V_21 -> V_24 . type = V_25 ;
V_21 -> V_31 . V_3 = * V_35 ;
V_21 -> V_31 . V_3 . V_37 [ 0 ] &= V_36 -> V_37 [ 0 ] ;
V_21 -> V_31 . V_3 . V_37 [ 1 ] &= V_36 -> V_37 [ 1 ] ;
V_21 -> V_31 . V_3 . V_37 [ 2 ] &= V_36 -> V_37 [ 2 ] ;
V_21 -> V_31 . V_3 . V_37 [ 3 ] &= V_36 -> V_37 [ 3 ] ;
V_21 -> V_31 . V_4 = * V_36 ;
V_21 -> V_31 . V_33 = 1 ;
V_12 = F_11 ( & V_21 -> V_31 ,
& V_17 -> V_27 ) ;
if ( V_12 != 0 )
goto V_23;
break;
}
#endif
default:
goto V_23;
}
V_15 -> V_24 . V_38 = V_17 ;
V_15 -> V_24 . type = V_39 ;
} else {
V_12 = - V_11 ;
goto V_23;
}
V_12 = F_12 ( V_15 , V_6 ) ;
if ( V_12 != 0 )
goto V_23;
return 0 ;
V_23:
F_13 ( V_15 -> V_1 ) ;
F_13 ( V_15 ) ;
F_13 ( V_17 ) ;
F_13 ( V_19 ) ;
F_13 ( V_21 ) ;
return V_12 ;
}
int F_14 ( struct V_40 * V_40 ,
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
V_43 = sizeof( struct V_28 ) ;
break;
#if F_4 ( V_8 )
case V_9 :
V_43 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_10 ;
}
return F_15 ( V_40 ,
V_41 , V_3 , V_4 , V_43 ,
V_42 , V_6 ) ;
}
int F_16 ( struct V_40 * V_40 ,
const char * V_41 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
struct V_5 * V_6 )
{
T_2 V_43 ;
switch ( V_2 ) {
case V_7 :
V_43 = sizeof( struct V_28 ) ;
break;
#if F_4 ( V_8 )
case V_9 :
V_43 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_10 ;
}
return F_17 ( V_40 ,
V_41 , V_3 , V_4 , V_43 ,
V_6 ) ;
}
int F_18 ( struct V_44 * V_45 ,
struct V_5 * V_6 )
{
return F_19 ( V_45 , V_6 ) ;
}
void F_20 ( T_2 V_46 , struct V_5 * V_6 )
{
F_21 ( V_46 , V_6 ) ;
}
int F_22 ( T_2 V_46 ,
const char * V_1 ,
const struct V_28 * V_3 ,
const struct V_28 * V_4 ,
struct V_5 * V_6 )
{
int V_12 = - V_13 ;
struct V_44 * V_45 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_47 = NULL ;
V_45 = F_23 ( V_46 ) ;
if ( V_45 == NULL )
return - V_48 ;
V_15 = F_7 ( sizeof( * V_15 ) , V_22 ) ;
if ( V_15 == NULL )
goto V_49;
V_15 -> V_2 = V_7 ;
if ( V_1 != NULL ) {
V_15 -> V_1 = F_8 ( V_1 , V_22 ) ;
if ( V_15 -> V_1 == NULL )
goto V_50;
}
if ( V_3 == NULL && V_4 == NULL ) {
V_15 -> V_24 . V_51 = V_45 ;
V_15 -> V_24 . type = V_52 ;
} else if ( V_3 != NULL && V_4 != NULL ) {
V_17 = F_7 ( sizeof( * V_17 ) , V_22 ) ;
if ( V_17 == NULL )
goto V_53;
F_9 ( & V_17 -> V_26 ) ;
F_9 ( & V_17 -> V_27 ) ;
V_47 = F_7 ( sizeof( * V_47 ) , V_22 ) ;
if ( V_47 == NULL )
goto V_54;
V_47 -> V_24 . V_51 = V_45 ;
V_47 -> V_24 . type = V_52 ;
V_47 -> V_31 . V_3 = V_3 -> V_32 & V_4 -> V_32 ;
V_47 -> V_31 . V_4 = V_4 -> V_32 ;
V_47 -> V_31 . V_33 = 1 ;
V_12 = F_10 ( & V_47 -> V_31 , & V_17 -> V_26 ) ;
if ( V_12 != 0 )
goto V_55;
V_15 -> V_24 . V_38 = V_17 ;
V_15 -> V_24 . type = V_39 ;
} else {
V_12 = - V_11 ;
goto V_53;
}
V_12 = F_12 ( V_15 , V_6 ) ;
if ( V_12 != 0 )
goto V_55;
return 0 ;
V_55:
F_13 ( V_47 ) ;
V_54:
F_13 ( V_17 ) ;
V_53:
F_13 ( V_15 -> V_1 ) ;
V_50:
F_13 ( V_15 ) ;
V_49:
F_24 ( V_45 ) ;
return V_12 ;
}
int F_25 ( struct V_56 * V_45 ,
struct V_5 * V_6 )
{
#if F_4 ( V_8 )
return F_26 ( V_45 , V_6 ) ;
#else
return - V_57 ;
#endif
}
void F_27 ( T_2 V_46 , struct V_5 * V_6 )
{
#if F_4 ( V_8 )
F_28 ( V_46 , V_6 ) ;
#endif
}
int F_29 ( T_2 V_46 ,
const char * V_1 ,
const struct V_34 * V_3 ,
const struct V_34 * V_4 ,
struct V_5 * V_6 )
{
#if F_4 ( V_8 )
int V_12 = - V_13 ;
struct V_56 * V_45 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = NULL ;
struct V_20 * V_47 = NULL ;
V_45 = F_30 ( V_46 ) ;
if ( V_45 == NULL )
return - V_48 ;
V_15 = F_7 ( sizeof( * V_15 ) , V_22 ) ;
if ( V_15 == NULL )
goto V_49;
V_15 -> V_2 = V_9 ;
if ( V_1 != NULL ) {
V_15 -> V_1 = F_8 ( V_1 , V_22 ) ;
if ( V_15 -> V_1 == NULL )
goto V_50;
}
if ( V_3 == NULL && V_4 == NULL ) {
V_15 -> V_24 . V_58 = V_45 ;
V_15 -> V_24 . type = V_59 ;
} else if ( V_3 != NULL && V_4 != NULL ) {
V_17 = F_7 ( sizeof( * V_17 ) , V_22 ) ;
if ( V_17 == NULL )
goto V_53;
F_9 ( & V_17 -> V_26 ) ;
F_9 ( & V_17 -> V_27 ) ;
V_47 = F_7 ( sizeof( * V_47 ) , V_22 ) ;
if ( V_47 == NULL )
goto V_54;
V_47 -> V_24 . V_58 = V_45 ;
V_47 -> V_24 . type = V_59 ;
V_47 -> V_31 . V_3 = * V_3 ;
V_47 -> V_31 . V_3 . V_37 [ 0 ] &= V_4 -> V_37 [ 0 ] ;
V_47 -> V_31 . V_3 . V_37 [ 1 ] &= V_4 -> V_37 [ 1 ] ;
V_47 -> V_31 . V_3 . V_37 [ 2 ] &= V_4 -> V_37 [ 2 ] ;
V_47 -> V_31 . V_3 . V_37 [ 3 ] &= V_4 -> V_37 [ 3 ] ;
V_47 -> V_31 . V_4 = * V_4 ;
V_47 -> V_31 . V_33 = 1 ;
V_12 = F_11 ( & V_47 -> V_31 , & V_17 -> V_27 ) ;
if ( V_12 != 0 )
goto V_60;
V_15 -> V_24 . V_38 = V_17 ;
V_15 -> V_24 . type = V_39 ;
} else {
V_12 = - V_11 ;
goto V_53;
}
V_12 = F_12 ( V_15 , V_6 ) ;
if ( V_12 != 0 )
goto V_60;
return 0 ;
V_60:
F_13 ( V_47 ) ;
V_54:
F_13 ( V_17 ) ;
V_53:
F_13 ( V_15 -> V_1 ) ;
V_50:
F_13 ( V_15 ) ;
V_49:
F_31 ( V_45 ) ;
return V_12 ;
#else
return - V_57 ;
#endif
}
static struct V_61 * F_32 (
struct V_61 * * V_62 ,
T_2 V_63 ,
unsigned int V_64 ,
T_3 V_65 )
{
struct V_61 * V_66 = * V_62 ;
struct V_61 * V_67 = NULL ;
if ( V_66 == NULL )
goto V_68;
if ( V_63 < V_66 -> V_69 )
goto V_70;
while ( V_66 && V_63 >= ( V_66 -> V_69 + V_71 ) ) {
V_67 = V_66 ;
V_66 = V_66 -> V_72 ;
}
if ( V_66 == NULL || V_63 < V_66 -> V_69 )
goto V_70;
return V_66 ;
V_70:
if ( V_64 & V_73 )
return V_66 ;
V_68:
if ( ! ( V_64 & V_74 ) )
return NULL ;
V_66 = F_33 ( V_65 ) ;
if ( V_66 == NULL )
return NULL ;
V_66 -> V_69 = V_63 & ~ ( V_71 - 1 ) ;
if ( V_67 == NULL ) {
V_66 -> V_72 = * V_62 ;
* V_62 = V_66 ;
} else {
V_66 -> V_72 = V_67 -> V_72 ;
V_67 -> V_72 = V_66 ;
}
return V_66 ;
}
int F_34 ( struct V_61 * V_62 , T_2 V_63 )
{
struct V_61 * V_66 = V_62 ;
T_2 V_75 ;
T_2 V_76 ;
T_4 V_77 ;
V_66 = F_32 ( & V_62 , V_63 , V_73 , 0 ) ;
if ( V_66 == NULL )
return - V_48 ;
if ( V_63 > V_66 -> V_69 ) {
V_63 -= V_66 -> V_69 ;
V_75 = V_63 / V_78 ;
V_76 = V_63 % V_78 ;
} else {
V_75 = 0 ;
V_76 = 0 ;
}
V_77 = V_66 -> V_77 [ V_75 ] >> V_76 ;
for (; ; ) {
if ( V_77 != 0 ) {
while ( ( V_77 & V_79 ) == 0 ) {
V_77 >>= 1 ;
V_76 ++ ;
}
return V_66 -> V_69 +
( V_78 * V_75 ) + V_76 ;
}
if ( ++ V_75 >= V_80 ) {
if ( V_66 -> V_72 != NULL ) {
V_66 = V_66 -> V_72 ;
V_75 = 0 ;
} else
return - V_48 ;
}
V_77 = V_66 -> V_77 [ V_75 ] ;
V_76 = 0 ;
}
return - V_48 ;
}
int F_35 ( struct V_61 * V_62 , T_2 V_63 )
{
struct V_61 * V_66 ;
struct V_61 * V_67 = NULL ;
T_2 V_75 ;
T_2 V_76 ;
T_4 V_81 ;
T_4 V_77 ;
V_66 = F_32 ( & V_62 , V_63 , V_73 , 0 ) ;
if ( V_66 == NULL )
return - V_48 ;
if ( V_63 > V_66 -> V_69 ) {
V_63 -= V_66 -> V_69 ;
V_75 = V_63 / V_78 ;
V_76 = V_63 % V_78 ;
} else {
V_75 = 0 ;
V_76 = 0 ;
}
V_81 = V_79 << V_76 ;
for (; ; ) {
V_77 = V_66 -> V_77 [ V_75 ] ;
while ( V_81 != 0 && ( V_77 & V_81 ) != 0 ) {
V_81 <<= 1 ;
V_76 ++ ;
}
if ( V_67 && V_75 == 0 && V_76 == 0 )
return V_67 -> V_69 + V_71 - 1 ;
else if ( V_81 != 0 )
return V_66 -> V_69 +
( V_78 * V_75 ) + V_76 - 1 ;
else if ( ++ V_75 >= V_80 ) {
if ( V_66 -> V_72 == NULL )
return V_66 -> V_69 + V_71 - 1 ;
V_67 = V_66 ;
V_66 = V_66 -> V_72 ;
V_75 = 0 ;
}
V_81 = V_79 ;
V_76 = 0 ;
}
return - V_48 ;
}
int F_36 ( struct V_61 * V_62 ,
T_2 * V_63 ,
unsigned long * V_77 )
{
struct V_61 * V_66 ;
T_2 V_82 = * V_63 ;
T_2 V_75 ;
if ( ( V_82 & ( V_83 - 1 ) ) != 0 )
return - V_11 ;
if ( V_82 < V_62 -> V_69 ) {
V_82 = V_62 -> V_69 ;
* V_63 = V_82 ;
}
V_66 = F_32 ( & V_62 , V_82 , V_73 , 0 ) ;
if ( V_66 == NULL ) {
* V_63 = ( T_2 ) - 1 ;
return 0 ;
}
if ( V_82 < V_66 -> V_69 ) {
* V_63 = V_66 -> V_69 ;
V_82 = 0 ;
} else
V_82 -= V_66 -> V_69 ;
V_75 = V_82 / V_78 ;
* V_77 = V_66 -> V_77 [ V_75 ] >> ( V_82 % V_78 ) ;
return 0 ;
}
int F_37 ( struct V_61 * * V_62 ,
T_2 V_76 ,
T_3 V_84 )
{
struct V_61 * V_66 ;
T_2 V_75 ;
V_66 = F_32 ( V_62 , V_76 , V_74 , V_84 ) ;
if ( V_66 == NULL )
return - V_13 ;
V_76 -= V_66 -> V_69 ;
V_75 = V_76 / V_78 ;
V_66 -> V_77 [ V_75 ] |= V_79 << ( V_76 % V_78 ) ;
return 0 ;
}
int F_38 ( struct V_61 * * V_62 ,
T_2 V_85 ,
T_2 V_86 ,
T_3 V_84 )
{
int V_87 = 0 ;
T_2 V_88 = V_85 ;
while ( V_87 == 0 && V_88 <= V_86 ) {
if ( ( ( V_88 & ( V_83 - 1 ) ) == 0 ) &&
( ( V_86 - V_88 ) > V_83 ) ) {
V_87 = F_39 ( V_62 ,
V_88 ,
( unsigned long ) - 1 ,
V_84 ) ;
V_88 += V_83 ;
} else
V_87 = F_37 ( V_62 , V_88 ++ , V_84 ) ;
}
return V_87 ;
}
int F_39 ( struct V_61 * * V_62 ,
T_2 V_63 ,
unsigned long V_77 ,
T_3 V_84 )
{
struct V_61 * V_66 ;
T_2 V_75 ;
if ( ( V_63 & ( V_83 - 1 ) ) != 0 )
return - V_11 ;
V_66 = F_32 ( V_62 , V_63 , V_74 , V_84 ) ;
if ( V_66 == NULL )
return - V_13 ;
V_63 -= V_66 -> V_69 ;
V_75 = V_63 / V_78 ;
V_66 -> V_77 [ V_75 ] |= V_77 << ( V_63 % V_78 ) ;
return 0 ;
}
int F_40 ( const unsigned char * V_77 , T_2 V_89 ,
T_2 V_63 , T_5 V_90 )
{
T_2 V_91 ;
T_2 V_92 ;
unsigned char V_81 ;
unsigned char V_93 ;
V_92 = V_63 / 8 ;
V_93 = V_77 [ V_92 ] ;
V_91 = V_63 ;
V_81 = 0x80 >> ( V_63 % 8 ) ;
while ( V_91 < V_89 ) {
if ( ( V_90 && ( V_93 & V_81 ) == V_81 ) ||
( V_90 == 0 && ( V_93 & V_81 ) == 0 ) )
return V_91 ;
V_91 ++ ;
V_81 >>= 1 ;
if ( V_81 == 0 ) {
V_93 = V_77 [ ++ V_92 ] ;
V_81 = 0x80 ;
}
}
return - 1 ;
}
void F_41 ( unsigned char * V_77 , T_2 V_76 , T_5 V_90 )
{
T_2 V_94 ;
T_5 V_81 ;
V_94 = V_76 / 8 ;
V_81 = 0x80 >> ( V_76 % 8 ) ;
if ( V_90 )
V_77 [ V_94 ] |= V_81 ;
else
V_77 [ V_94 ] &= ~ V_81 ;
}
int F_42 ( void )
{
return ( F_43 ( & V_95 ) > 0 ) ;
}
int F_44 ( struct V_96 * V_97 ,
T_1 V_2 ,
const struct V_98 * V_99 )
{
int V_12 ;
struct V_14 * V_100 ;
F_45 () ;
V_100 = F_46 ( V_99 -> V_1 , V_2 ) ;
if ( V_100 == NULL ) {
V_12 = - V_48 ;
goto V_101;
}
switch ( V_2 ) {
case V_7 :
switch ( V_100 -> V_24 . type ) {
case V_39 :
V_12 = - V_102 ;
break;
case V_52 :
V_12 = F_47 ( V_97 ,
V_100 -> V_24 . V_51 ,
V_99 ) ;
break;
case V_25 :
V_12 = 0 ;
break;
default:
V_12 = - V_48 ;
}
break;
#if F_4 ( V_8 )
case V_9 :
switch ( V_100 -> V_24 . type ) {
case V_39 :
V_12 = - V_102 ;
break;
case V_59 :
V_12 = F_48 ( V_97 ,
V_100 -> V_24 . V_58 ,
V_99 ) ;
break;
case V_25 :
V_12 = 0 ;
break;
default:
V_12 = - V_48 ;
}
break;
#endif
default:
V_12 = - V_103 ;
}
V_101:
F_49 () ;
return V_12 ;
}
void F_50 ( struct V_96 * V_97 )
{
switch ( V_97 -> V_104 ) {
case V_7 :
F_51 ( V_97 ) ;
break;
#if F_4 ( V_8 )
case V_9 :
F_52 ( V_97 ) ;
break;
#endif
}
}
int F_53 ( struct V_96 * V_97 ,
struct V_98 * V_99 )
{
int V_12 ;
switch ( V_97 -> V_104 ) {
case V_7 :
V_12 = F_54 ( V_97 , V_99 ) ;
break;
#if F_4 ( V_8 )
case V_9 :
V_12 = F_55 ( V_97 , V_99 ) ;
break;
#endif
default:
V_12 = - V_103 ;
}
return V_12 ;
}
int F_56 ( struct V_96 * V_97 ,
struct V_105 * V_3 ,
const struct V_98 * V_99 )
{
int V_12 ;
struct V_106 * V_29 ;
#if F_4 ( V_8 )
struct V_107 * V_35 ;
#endif
struct V_108 * V_15 ;
F_45 () ;
switch ( V_3 -> V_109 ) {
case V_7 :
V_29 = (struct V_106 * ) V_3 ;
V_15 = F_57 ( V_99 -> V_1 ,
V_29 -> V_110 . V_32 ) ;
if ( V_15 == NULL ) {
V_12 = - V_48 ;
goto V_111;
}
switch ( V_15 -> type ) {
case V_52 :
V_12 = F_47 ( V_97 ,
V_15 -> V_51 , V_99 ) ;
break;
case V_25 :
F_50 ( V_97 ) ;
V_12 = 0 ;
break;
default:
V_12 = - V_48 ;
}
break;
#if F_4 ( V_8 )
case V_9 :
V_35 = (struct V_107 * ) V_3 ;
V_15 = F_58 ( V_99 -> V_1 ,
& V_35 -> V_112 ) ;
if ( V_15 == NULL ) {
V_12 = - V_48 ;
goto V_111;
}
switch ( V_15 -> type ) {
case V_59 :
V_12 = F_48 ( V_97 ,
V_15 -> V_58 , V_99 ) ;
break;
case V_25 :
F_50 ( V_97 ) ;
V_12 = 0 ;
break;
default:
V_12 = - V_48 ;
}
break;
#endif
default:
V_12 = - V_103 ;
}
V_111:
F_49 () ;
return V_12 ;
}
int F_59 ( struct V_113 * V_114 ,
const struct V_98 * V_99 )
{
int V_12 ;
struct V_108 * V_15 ;
struct V_115 * V_116 = F_60 ( V_114 ) ;
F_45 () ;
switch ( V_114 -> V_117 -> V_2 ) {
case V_7 :
V_15 = F_57 ( V_99 -> V_1 ,
V_116 -> V_118 ) ;
if ( V_15 == NULL ) {
V_12 = - V_48 ;
goto V_119;
}
switch ( V_15 -> type ) {
case V_52 :
V_12 = F_61 ( V_114 ,
V_15 -> V_51 , V_99 ) ;
break;
case V_25 :
F_62 ( V_114 ) ;
V_12 = 0 ;
break;
default:
V_12 = - V_48 ;
}
break;
#if F_4 ( V_8 )
case V_9 :
V_15 = F_58 ( V_99 -> V_1 ,
& V_116 -> V_120 ) ;
if ( V_15 == NULL ) {
V_12 = - V_48 ;
goto V_119;
}
switch ( V_15 -> type ) {
case V_59 :
V_12 = F_63 ( V_114 ,
V_15 -> V_58 , V_99 ) ;
break;
case V_25 :
F_62 ( V_114 ) ;
V_12 = 0 ;
break;
default:
V_12 = - V_48 ;
}
break;
#endif
default:
V_12 = - V_103 ;
}
V_119:
F_49 () ;
return V_12 ;
}
void F_62 ( struct V_113 * V_114 )
{
switch ( V_114 -> V_117 -> V_2 ) {
case V_7 :
F_64 ( V_114 ) ;
break;
#if F_4 ( V_8 )
case V_9 :
F_65 ( V_114 ) ;
break;
#endif
}
}
int F_66 ( struct V_121 * V_122 ,
T_1 V_2 ,
const struct V_98 * V_99 )
{
int V_12 ;
struct V_123 * V_124 ;
#if F_4 ( V_8 )
struct V_125 * V_126 ;
#endif
struct V_108 * V_15 ;
F_45 () ;
switch ( V_2 ) {
case V_7 :
V_124 = F_67 ( V_122 ) ;
V_15 = F_57 ( V_99 -> V_1 ,
V_124 -> V_127 ) ;
if ( V_15 == NULL ) {
V_12 = - V_48 ;
goto V_128;
}
switch ( V_15 -> type ) {
case V_52 :
V_12 = F_68 ( V_122 , V_15 -> V_51 ,
V_99 ) ;
break;
case V_25 :
V_12 = F_69 ( V_122 ) ;
break;
default:
V_12 = - V_48 ;
}
break;
#if F_4 ( V_8 )
case V_9 :
V_126 = F_70 ( V_122 ) ;
V_15 = F_58 ( V_99 -> V_1 ,
& V_126 -> V_127 ) ;
if ( V_15 == NULL ) {
V_12 = - V_48 ;
goto V_128;
}
switch ( V_15 -> type ) {
case V_59 :
V_12 = F_71 ( V_122 , V_15 -> V_58 ,
V_99 ) ;
break;
case V_25 :
V_12 = F_72 ( V_122 ) ;
break;
default:
V_12 = - V_48 ;
}
break;
#endif
default:
V_12 = - V_103 ;
}
V_128:
F_49 () ;
return V_12 ;
}
int F_73 ( const struct V_121 * V_122 ,
T_1 V_2 ,
struct V_98 * V_99 )
{
unsigned char * V_129 ;
switch ( V_2 ) {
case V_7 :
V_129 = F_74 ( V_122 ) ;
if ( V_129 && F_75 ( V_129 , V_99 ) == 0 )
return 0 ;
break;
#if F_4 ( V_8 )
case V_9 :
V_129 = F_76 ( V_122 ) ;
if ( V_129 && F_77 ( V_129 , V_99 ) == 0 )
return 0 ;
break;
#endif
}
return F_78 ( V_122 , V_2 , V_99 ) ;
}
void F_79 ( struct V_121 * V_122 , T_1 V_2 , int error , int V_130 )
{
switch ( V_2 ) {
case V_7 :
if ( F_74 ( V_122 ) )
F_80 ( V_122 , error , V_130 ) ;
break;
}
}
void F_81 ( void )
{
F_82 () ;
#if F_4 ( V_8 )
F_83 () ;
#endif
}
int F_84 ( const struct V_121 * V_122 , T_1 V_2 ,
const struct V_98 * V_99 )
{
unsigned char * V_129 ;
if ( ( V_99 -> V_84 & V_131 ) == 0 )
return - V_132 ;
switch ( V_2 ) {
case V_7 :
V_129 = F_74 ( V_122 ) ;
if ( V_129 )
return F_85 ( V_129 , V_99 ) ;
break;
#if F_4 ( V_8 )
case V_9 :
V_129 = F_76 ( V_122 ) ;
if ( V_129 )
return F_86 ( V_129 , V_99 ) ;
break;
#endif
}
return - V_132 ;
}
struct V_133 * F_87 ( int type ,
struct V_5 * V_6 )
{
return F_88 ( type , V_6 ) ;
}
static int T_6 F_89 ( void )
{
int V_12 ;
F_90 ( V_134 L_1 ) ;
F_90 ( V_134 L_2 ,
( 1 << V_135 ) ) ;
F_90 ( V_134 L_3
L_4
L_5
L_6 ) ;
V_12 = F_91 ( V_135 ) ;
if ( V_12 != 0 )
goto V_136;
V_12 = F_92 ( V_137 ) ;
if ( V_12 != 0 )
goto V_136;
V_12 = F_93 () ;
if ( V_12 != 0 )
goto V_136;
V_12 = F_94 () ;
if ( V_12 != 0 )
goto V_136;
F_90 ( V_134 L_7 ) ;
return 0 ;
V_136:
F_95 ( L_8 , V_12 ) ;
}
