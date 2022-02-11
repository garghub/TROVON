int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_8 ;
T_1 V_9 , V_10 ;
int V_11 ;
V_9 = V_4 -> V_12 ;
V_11 = F_2 ( V_6 , F_3 ( V_6 , V_4 ) -> V_13 + 1 , F_3 ( V_6 , V_4 ) -> V_13 [ 0 ] ) ;
F_4 ( L_1 , ( T_1 ) V_2 -> V_14 , V_9 ) ;
V_8 = F_5 ( V_6 , V_2 -> V_14 ) ;
if ( ! V_8 )
return - V_15 ;
V_10 = F_6 ( F_7 ( V_8 ) -> V_16 [ V_11 ] ) ;
while ( V_10 ) {
F_8 ( V_8 ) ;
V_8 = F_5 ( V_6 , V_10 ) ;
if ( ! V_8 )
return - V_15 ;
V_10 = F_6 ( F_3 ( V_6 , V_8 ) -> V_17 ) ;
}
F_3 ( V_6 , V_4 ) -> V_18 = F_9 ( V_2 -> V_14 ) ;
F_3 ( V_6 , V_4 ) -> V_17 = 0 ;
F_10 ( V_6 , V_4 ) ;
if ( V_2 -> V_14 == V_8 -> V_12 )
F_7 ( V_8 ) -> V_16 [ V_11 ] = F_9 ( V_9 ) ;
else
F_3 ( V_6 , V_8 ) -> V_17 = F_9 ( V_9 ) ;
F_11 ( V_8 , V_9 ) ;
F_12 ( V_8 , V_2 ) ;
F_8 ( V_8 ) ;
V_2 -> V_19 = V_2 -> V_20 = V_21 ;
V_2 -> V_22 ++ ;
F_13 ( V_2 ) ;
return 0 ;
}
int
F_14 ( struct V_1 * V_2 , struct V_3 * V_23 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_1 V_24 , V_10 ;
T_2 V_9 ;
int V_11 , V_25 ;
V_6 = V_2 -> V_7 ;
V_24 = V_23 -> V_12 ;
V_11 = F_2 ( V_6 , F_3 ( V_6 , V_23 ) -> V_13 + 1 , F_3 ( V_6 , V_23 ) -> V_13 [ 0 ] ) ;
F_4 ( L_2 , ( T_1 ) V_2 -> V_14 , V_24 , V_11 ) ;
V_4 = F_5 ( V_6 , V_2 -> V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_25 = - V_26 ;
V_10 = F_6 ( F_7 ( V_4 ) -> V_16 [ V_11 ] ) ;
while ( V_10 ) {
if ( V_10 == V_24 ) {
V_9 = F_3 ( V_6 , V_23 ) -> V_17 ;
if ( V_2 -> V_14 == V_4 -> V_12 )
F_7 ( V_4 ) -> V_16 [ V_11 ] = V_9 ;
else
F_3 ( V_6 , V_4 ) -> V_17 = V_9 ;
F_11 ( V_4 , F_6 ( V_9 ) - V_10 ) ;
F_12 ( V_4 , V_2 ) ;
F_3 ( V_6 , V_23 ) -> V_18 = 0 ;
V_25 = 0 ;
break;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_10 ) ;
if ( ! V_4 )
return - V_15 ;
V_10 = F_6 ( F_3 ( V_6 , V_4 ) -> V_17 ) ;
}
F_8 ( V_4 ) ;
V_2 -> V_19 = V_2 -> V_20 = V_21 ;
V_2 -> V_22 ++ ;
F_13 ( V_2 ) ;
return V_25 ;
}
static void
F_15 ( struct V_27 * V_27 , T_1 V_28 )
{
struct V_1 * V_1 = V_27 -> V_29 ;
void * V_30 = V_27 -> V_31 ;
struct V_32 * V_33 , * V_34 ;
F_16 ( & V_1 -> V_35 ) ;
V_33 = & V_1 -> V_36 ;
V_34 = V_33 -> V_34 ;
while ( V_34 != V_33 ) {
V_27 = F_17 ( V_34 , struct V_27 , V_37 ) ;
if ( V_28 == ( T_1 ) ( long ) V_27 -> V_31 ) {
V_27 -> V_31 = V_30 ;
break;
}
V_34 = V_34 -> V_34 ;
}
F_18 ( & V_1 -> V_35 ) ;
}
static int
F_19 ( struct V_27 * V_27 )
{
struct V_1 * V_2 , * V_1 = V_27 -> V_29 ;
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 = NULL , * V_38 = NULL ;
T_1 V_39 , V_9 ;
int V_25 ;
F_4 ( L_3 , V_1 -> V_14 ) ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , V_1 -> V_14 ) ;
if ( ! V_4 )
goto V_40;
V_39 = ( T_1 ) ( long ) V_27 -> V_31 ;
if ( V_1 -> V_14 == V_39 ) {
V_39 = F_6 ( F_3 ( V_6 , V_4 ) -> V_41 ) ;
V_38 = F_5 ( V_6 , V_39 ) ;
if ( ! V_38 )
goto V_40;
V_2 = F_20 ( V_6 , F_6 ( F_3 ( V_6 , V_38 ) -> V_18 ) ) ;
if ( F_21 ( V_2 ) ) {
V_25 = F_22 ( V_2 ) ;
goto V_40;
}
F_23 ( V_2 ) ;
F_15 ( V_27 , V_39 ) ;
V_25 = F_14 ( V_2 , V_38 ) ;
if ( V_25 ) {
F_24 ( V_2 ) ;
goto V_40;
}
F_12 ( V_38 , V_1 ) ;
memcpy ( F_3 ( V_6 , V_4 ) -> V_13 , F_3 ( V_6 , V_38 ) -> V_13 , 32 ) ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( V_25 ) {
F_24 ( V_2 ) ;
goto V_40;
}
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
} else {
V_38 = F_5 ( V_6 , V_39 ) ;
if ( ! V_38 )
goto V_40;
}
while ( ( V_9 = F_6 ( F_3 ( V_6 , V_4 ) -> V_41 ) ) != 0 ) {
if ( V_9 == V_39 ) {
T_2 V_42 = F_3 ( V_6 , V_38 ) -> V_41 ;
F_3 ( V_6 , V_4 ) -> V_41 = V_42 ;
F_11 ( V_4 , F_6 ( V_42 ) - V_39 ) ;
F_12 ( V_4 , V_1 ) ;
V_25 = 0 ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_43 ) ) {
case V_44 :
case V_45 :
break;
default:
if ( ! F_3 ( V_6 , V_4 ) -> V_41 )
F_26 ( V_1 , 1 ) ;
}
F_27 ( V_6 , V_39 ) ;
goto V_40;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_9 ) ;
if ( ! V_4 )
goto V_40;
}
V_25 = - V_26 ;
V_40:
F_8 ( V_38 ) ;
F_8 ( V_4 ) ;
return V_25 ;
}
static int
F_28 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 ;
int V_25 , V_46 ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , V_1 -> V_14 ) ;
if ( ! V_4 )
goto V_40;
V_25 = - V_47 ;
for ( V_46 = F_29 ( V_6 ) -> V_48 - 1 ; V_46 >= 0 ; V_46 -- )
if ( F_7 ( V_4 ) -> V_16 [ V_46 ] )
goto V_49;
V_25 = 0 ;
V_49:
F_8 ( V_4 ) ;
V_40:
return V_25 ;
}
int
F_30 ( struct V_27 * V_27 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 , * V_2 ;
struct V_3 * V_4 = NULL ;
int V_25 ;
V_2 = V_27 -> V_50 -> V_29 ;
V_6 = V_2 -> V_7 ;
V_25 = - V_26 ;
V_1 = V_27 -> V_29 ;
if ( ! V_1 )
goto V_40;
F_4 ( L_4 , V_1 -> V_14 ) ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , ( T_1 ) ( long ) V_27 -> V_31 ) ;
if ( ! V_4 )
goto V_40;
F_31 ( V_1 ) ;
F_23 ( V_2 ) ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_43 ) ) {
case V_51 :
F_23 ( V_1 ) ;
V_25 = F_28 ( V_1 ) ;
F_24 ( V_1 ) ;
if ( V_25 )
goto V_52;
break;
default:
break;
}
V_25 = F_14 ( V_2 , V_4 ) ;
if ( V_25 )
goto V_52;
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
if ( V_1 -> V_53 > 1 )
V_25 = F_19 ( V_27 ) ;
else
F_32 ( V_1 ) ;
F_33 ( V_1 ) ;
V_1 -> V_20 = V_21 ;
F_13 ( V_1 ) ;
V_40:
F_8 ( V_4 ) ;
return V_25 ;
V_52:
F_24 ( V_2 ) ;
F_33 ( V_1 ) ;
goto V_40;
}
T_1
F_34 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
T_2 * V_54 = ( T_2 * ) V_4 -> V_55 ;
T_1 V_56 ;
int V_57 ;
V_56 = 0 ;
for ( V_57 = V_6 -> V_58 / sizeof( T_2 ) ; V_57 > 0 ; V_57 -- )
V_56 += F_6 ( * V_54 ++ ) ;
return V_56 ;
}
void
F_10 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_59 = V_6 -> V_58 / sizeof( T_2 ) ;
T_2 * V_54 = ( T_2 * ) V_4 -> V_55 ;
T_1 V_60 ;
T_2 * V_61 ;
V_61 = V_54 + 5 ;
* V_61 = 0 ;
for ( V_60 = 0 ; V_59 > 0 ; V_54 ++ , V_59 -- )
V_60 += F_6 ( * V_54 ) ;
* V_61 = F_9 ( - V_60 ) ;
}
void
F_35 ( T_3 V_62 , struct V_63 * V_64 )
{
T_1 V_65 ;
T_1 V_66 ;
V_62 -= V_67 . V_68 * 60 + ( ( 8 * 365 + 2 ) * 24 * 60 * 60 ) ;
if ( V_62 < 0 )
V_62 = 0 ;
V_65 = V_62 / 86400 ;
V_62 -= V_65 * 86400 ;
V_66 = V_62 / 60 ;
V_62 -= V_66 * 60 ;
V_64 -> V_65 = F_9 ( V_65 ) ;
V_64 -> V_69 = F_9 ( V_66 ) ;
V_64 -> V_70 = F_9 ( V_62 * 50 ) ;
}
T_4
F_36 ( T_1 V_71 )
{
T_4 V_72 = 0 ;
if ( ! ( V_71 & V_73 ) )
V_72 |= V_74 ;
if ( ! ( V_71 & V_75 ) )
V_72 |= V_76 ;
if ( ! ( V_71 & V_77 ) )
V_72 |= V_78 ;
if ( V_71 & V_79 )
V_72 |= V_80 ;
if ( V_71 & V_81 )
V_72 |= V_82 ;
if ( V_71 & V_83 )
V_72 |= V_84 ;
if ( V_71 & V_85 )
V_72 |= V_86 ;
if ( V_71 & V_87 )
V_72 |= V_88 ;
if ( V_71 & V_89 )
V_72 |= V_90 ;
return V_72 ;
}
void
F_37 ( struct V_1 * V_1 )
{
T_1 V_71 = F_38 ( V_1 ) -> V_91 ;
T_4 V_72 = V_1 -> V_92 ;
if ( ! ( V_72 & V_78 ) )
V_71 |= V_77 ;
if ( ! ( V_72 & V_76 ) )
V_71 |= V_75 ;
if ( ! ( V_72 & V_74 ) )
V_71 |= V_73 ;
if ( V_72 & V_84 )
V_71 |= V_83 ;
if ( V_72 & V_82 )
V_71 |= V_81 ;
if ( V_72 & V_80 )
V_71 |= V_79 ;
if ( V_72 & V_90 )
V_71 |= V_89 ;
if ( V_72 & V_88 )
V_71 |= V_87 ;
if ( V_72 & V_86 )
V_71 |= V_85 ;
F_38 ( V_1 ) -> V_91 = V_71 ;
}
void
F_39 ( struct V_5 * V_6 , const char * V_93 , const char * V_94 , ... )
{
T_5 args ;
va_start ( args , V_94 ) ;
vsnprintf ( V_95 , sizeof( V_95 ) , V_94 , args ) ;
va_end ( args ) ;
F_40 ( V_96 L_5 , V_6 -> V_97 ,
V_93 , V_95 ) ;
if ( ! ( V_6 -> V_98 & V_99 ) )
F_40 ( V_100 L_6 ) ;
V_6 -> V_98 |= V_99 ;
}
void
F_41 ( struct V_5 * V_6 , const char * V_93 , const char * V_94 , ... )
{
T_5 args ;
va_start ( args , V_94 ) ;
vsnprintf ( V_95 , sizeof( V_95 ) , V_94 , args ) ;
va_end ( args ) ;
F_40 ( V_100 L_7 , V_6 -> V_97 ,
V_93 , V_95 ) ;
}
int
F_42 ( const unsigned char * V_13 , int V_101 )
{
int V_102 ;
if ( V_101 > 30 )
#ifdef F_43
return - V_103 ;
#else
V_101 = 30 ;
#endif
for ( V_102 = 0 ; V_102 < V_101 ; V_102 ++ ) {
if ( V_13 [ V_102 ] < ' ' || V_13 [ V_102 ] == ':'
|| ( V_13 [ V_102 ] > 0x7e && V_13 [ V_102 ] < 0xa0 ) )
return - V_104 ;
}
return 0 ;
}
int
F_44 ( unsigned char * V_105 , struct V_27 * V_27 )
{
int V_101 = F_45 ( V_27 -> V_106 . V_101 , 30u ) ;
* V_105 ++ = V_101 ;
memcpy ( V_105 , V_27 -> V_106 . V_13 , V_101 ) ;
return V_101 ;
}
