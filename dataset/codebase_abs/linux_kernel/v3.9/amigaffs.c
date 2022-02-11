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
F_15 ( struct V_1 * V_1 , T_1 V_27 )
{
struct V_28 * V_28 ;
F_16 ( & V_1 -> V_29 ) ;
F_17 (dentry, &inode->i_dentry, d_alias) {
if ( V_27 == ( T_1 ) ( long ) V_28 -> V_30 ) {
V_28 -> V_30 = ( void * ) V_1 -> V_14 ;
break;
}
}
F_18 ( & V_1 -> V_29 ) ;
}
static int
F_19 ( struct V_28 * V_28 )
{
struct V_1 * V_2 , * V_1 = V_28 -> V_31 ;
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 = NULL , * V_32 = NULL ;
T_1 V_33 , V_9 ;
int V_25 ;
F_4 ( L_3 , V_1 -> V_14 ) ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , V_1 -> V_14 ) ;
if ( ! V_4 )
goto V_34;
V_33 = ( T_1 ) ( long ) V_28 -> V_30 ;
if ( V_1 -> V_14 == V_33 ) {
V_33 = F_6 ( F_3 ( V_6 , V_4 ) -> V_35 ) ;
V_32 = F_5 ( V_6 , V_33 ) ;
if ( ! V_32 )
goto V_34;
V_2 = F_20 ( V_6 , F_6 ( F_3 ( V_6 , V_32 ) -> V_18 ) ) ;
if ( F_21 ( V_2 ) ) {
V_25 = F_22 ( V_2 ) ;
goto V_34;
}
F_23 ( V_2 ) ;
F_15 ( V_1 , V_33 ) ;
V_25 = F_14 ( V_2 , V_32 ) ;
if ( V_25 ) {
F_24 ( V_2 ) ;
goto V_34;
}
F_12 ( V_32 , V_1 ) ;
memcpy ( F_3 ( V_6 , V_4 ) -> V_13 , F_3 ( V_6 , V_32 ) -> V_13 , 32 ) ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( V_25 ) {
F_24 ( V_2 ) ;
goto V_34;
}
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
} else {
V_32 = F_5 ( V_6 , V_33 ) ;
if ( ! V_32 )
goto V_34;
}
while ( ( V_9 = F_6 ( F_3 ( V_6 , V_4 ) -> V_35 ) ) != 0 ) {
if ( V_9 == V_33 ) {
T_2 V_36 = F_3 ( V_6 , V_32 ) -> V_35 ;
F_3 ( V_6 , V_4 ) -> V_35 = V_36 ;
F_11 ( V_4 , F_6 ( V_36 ) - V_33 ) ;
F_12 ( V_4 , V_1 ) ;
V_25 = 0 ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_37 ) ) {
case V_38 :
case V_39 :
break;
default:
if ( ! F_3 ( V_6 , V_4 ) -> V_35 )
F_26 ( V_1 , 1 ) ;
}
F_27 ( V_6 , V_33 ) ;
goto V_34;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_9 ) ;
if ( ! V_4 )
goto V_34;
}
V_25 = - V_26 ;
V_34:
F_8 ( V_32 ) ;
F_8 ( V_4 ) ;
return V_25 ;
}
static int
F_28 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 ;
int V_25 , V_40 ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , V_1 -> V_14 ) ;
if ( ! V_4 )
goto V_34;
V_25 = - V_41 ;
for ( V_40 = F_29 ( V_6 ) -> V_42 - 1 ; V_40 >= 0 ; V_40 -- )
if ( F_7 ( V_4 ) -> V_16 [ V_40 ] )
goto V_43;
V_25 = 0 ;
V_43:
F_8 ( V_4 ) ;
V_34:
return V_25 ;
}
int
F_30 ( struct V_28 * V_28 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 , * V_2 ;
struct V_3 * V_4 = NULL ;
int V_25 ;
V_2 = V_28 -> V_44 -> V_31 ;
V_6 = V_2 -> V_7 ;
V_25 = - V_26 ;
V_1 = V_28 -> V_31 ;
if ( ! V_1 )
goto V_34;
F_4 ( L_4 , V_1 -> V_14 ) ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , ( T_1 ) ( long ) V_28 -> V_30 ) ;
if ( ! V_4 )
goto V_34;
F_31 ( V_1 ) ;
F_23 ( V_2 ) ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_37 ) ) {
case V_45 :
F_23 ( V_1 ) ;
V_25 = F_28 ( V_1 ) ;
F_24 ( V_1 ) ;
if ( V_25 )
goto V_46;
break;
default:
break;
}
V_25 = F_14 ( V_2 , V_4 ) ;
if ( V_25 )
goto V_46;
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
if ( V_1 -> V_47 > 1 )
V_25 = F_19 ( V_28 ) ;
else
F_32 ( V_1 ) ;
F_33 ( V_1 ) ;
V_1 -> V_20 = V_21 ;
F_13 ( V_1 ) ;
V_34:
F_8 ( V_4 ) ;
return V_25 ;
V_46:
F_24 ( V_2 ) ;
F_33 ( V_1 ) ;
goto V_34;
}
T_1
F_34 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
T_2 * V_48 = ( T_2 * ) V_4 -> V_49 ;
T_1 V_50 ;
int V_51 ;
V_50 = 0 ;
for ( V_51 = V_6 -> V_52 / sizeof( T_2 ) ; V_51 > 0 ; V_51 -- )
V_50 += F_6 ( * V_48 ++ ) ;
return V_50 ;
}
void
F_10 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_53 = V_6 -> V_52 / sizeof( T_2 ) ;
T_2 * V_48 = ( T_2 * ) V_4 -> V_49 ;
T_1 V_54 ;
T_2 * V_55 ;
V_55 = V_48 + 5 ;
* V_55 = 0 ;
for ( V_54 = 0 ; V_53 > 0 ; V_48 ++ , V_53 -- )
V_54 += F_6 ( * V_48 ) ;
* V_55 = F_9 ( - V_54 ) ;
}
void
F_35 ( T_3 V_56 , struct V_57 * V_58 )
{
T_1 V_59 ;
T_1 V_60 ;
V_56 -= V_61 . V_62 * 60 + ( ( 8 * 365 + 2 ) * 24 * 60 * 60 ) ;
if ( V_56 < 0 )
V_56 = 0 ;
V_59 = V_56 / 86400 ;
V_56 -= V_59 * 86400 ;
V_60 = V_56 / 60 ;
V_56 -= V_60 * 60 ;
V_58 -> V_59 = F_9 ( V_59 ) ;
V_58 -> V_63 = F_9 ( V_60 ) ;
V_58 -> V_64 = F_9 ( V_56 * 50 ) ;
}
T_4
F_36 ( T_1 V_65 )
{
T_4 V_66 = 0 ;
if ( ! ( V_65 & V_67 ) )
V_66 |= V_68 ;
if ( ! ( V_65 & V_69 ) )
V_66 |= V_70 ;
if ( ! ( V_65 & V_71 ) )
V_66 |= V_72 ;
if ( V_65 & V_73 )
V_66 |= V_74 ;
if ( V_65 & V_75 )
V_66 |= V_76 ;
if ( V_65 & V_77 )
V_66 |= V_78 ;
if ( V_65 & V_79 )
V_66 |= V_80 ;
if ( V_65 & V_81 )
V_66 |= V_82 ;
if ( V_65 & V_83 )
V_66 |= V_84 ;
return V_66 ;
}
void
F_37 ( struct V_1 * V_1 )
{
T_1 V_65 = F_38 ( V_1 ) -> V_85 ;
T_4 V_66 = V_1 -> V_86 ;
if ( ! ( V_66 & V_72 ) )
V_65 |= V_71 ;
if ( ! ( V_66 & V_70 ) )
V_65 |= V_69 ;
if ( ! ( V_66 & V_68 ) )
V_65 |= V_67 ;
if ( V_66 & V_78 )
V_65 |= V_77 ;
if ( V_66 & V_76 )
V_65 |= V_75 ;
if ( V_66 & V_74 )
V_65 |= V_73 ;
if ( V_66 & V_84 )
V_65 |= V_83 ;
if ( V_66 & V_82 )
V_65 |= V_81 ;
if ( V_66 & V_80 )
V_65 |= V_79 ;
F_38 ( V_1 ) -> V_85 = V_65 ;
}
void
F_39 ( struct V_5 * V_6 , const char * V_87 , const char * V_88 , ... )
{
T_5 args ;
va_start ( args , V_88 ) ;
vsnprintf ( V_89 , sizeof( V_89 ) , V_88 , args ) ;
va_end ( args ) ;
F_40 ( V_90 L_5 , V_6 -> V_91 ,
V_87 , V_89 ) ;
if ( ! ( V_6 -> V_92 & V_93 ) )
F_40 ( V_94 L_6 ) ;
V_6 -> V_92 |= V_93 ;
}
void
F_41 ( struct V_5 * V_6 , const char * V_87 , const char * V_88 , ... )
{
T_5 args ;
va_start ( args , V_88 ) ;
vsnprintf ( V_89 , sizeof( V_89 ) , V_88 , args ) ;
va_end ( args ) ;
F_40 ( V_94 L_7 , V_6 -> V_91 ,
V_87 , V_89 ) ;
}
int
F_42 ( const unsigned char * V_13 , int V_95 )
{
int V_96 ;
if ( V_95 > 30 )
#ifdef F_43
return - V_97 ;
#else
V_95 = 30 ;
#endif
for ( V_96 = 0 ; V_96 < V_95 ; V_96 ++ ) {
if ( V_13 [ V_96 ] < ' ' || V_13 [ V_96 ] == ':'
|| ( V_13 [ V_96 ] > 0x7e && V_13 [ V_96 ] < 0xa0 ) )
return - V_98 ;
}
return 0 ;
}
int
F_44 ( unsigned char * V_99 , struct V_28 * V_28 )
{
int V_95 = F_45 ( V_28 -> V_100 . V_95 , 30u ) ;
* V_99 ++ = V_95 ;
memcpy ( V_99 , V_28 -> V_100 . V_13 , V_95 ) ;
return V_95 ;
}
