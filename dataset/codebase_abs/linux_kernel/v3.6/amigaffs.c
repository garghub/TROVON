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
struct V_29 * V_30 ;
F_16 ( & V_1 -> V_31 ) ;
F_17 (dentry, p, &inode->i_dentry, d_alias) {
if ( V_27 == ( T_1 ) ( long ) V_28 -> V_32 ) {
V_28 -> V_32 = ( void * ) V_1 -> V_14 ;
break;
}
}
F_18 ( & V_1 -> V_31 ) ;
}
static int
F_19 ( struct V_28 * V_28 )
{
struct V_1 * V_2 , * V_1 = V_28 -> V_33 ;
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 = NULL , * V_34 = NULL ;
T_1 V_35 , V_9 ;
int V_25 ;
F_4 ( L_3 , V_1 -> V_14 ) ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , V_1 -> V_14 ) ;
if ( ! V_4 )
goto V_36;
V_35 = ( T_1 ) ( long ) V_28 -> V_32 ;
if ( V_1 -> V_14 == V_35 ) {
V_35 = F_6 ( F_3 ( V_6 , V_4 ) -> V_37 ) ;
V_34 = F_5 ( V_6 , V_35 ) ;
if ( ! V_34 )
goto V_36;
V_2 = F_20 ( V_6 , F_6 ( F_3 ( V_6 , V_34 ) -> V_18 ) ) ;
if ( F_21 ( V_2 ) ) {
V_25 = F_22 ( V_2 ) ;
goto V_36;
}
F_23 ( V_2 ) ;
F_15 ( V_1 , V_35 ) ;
V_25 = F_14 ( V_2 , V_34 ) ;
if ( V_25 ) {
F_24 ( V_2 ) ;
goto V_36;
}
F_12 ( V_34 , V_1 ) ;
memcpy ( F_3 ( V_6 , V_4 ) -> V_13 , F_3 ( V_6 , V_34 ) -> V_13 , 32 ) ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( V_25 ) {
F_24 ( V_2 ) ;
goto V_36;
}
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
} else {
V_34 = F_5 ( V_6 , V_35 ) ;
if ( ! V_34 )
goto V_36;
}
while ( ( V_9 = F_6 ( F_3 ( V_6 , V_4 ) -> V_37 ) ) != 0 ) {
if ( V_9 == V_35 ) {
T_2 V_38 = F_3 ( V_6 , V_34 ) -> V_37 ;
F_3 ( V_6 , V_4 ) -> V_37 = V_38 ;
F_11 ( V_4 , F_6 ( V_38 ) - V_35 ) ;
F_12 ( V_4 , V_1 ) ;
V_25 = 0 ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_39 ) ) {
case V_40 :
case V_41 :
break;
default:
if ( ! F_3 ( V_6 , V_4 ) -> V_37 )
F_26 ( V_1 , 1 ) ;
}
F_27 ( V_6 , V_35 ) ;
goto V_36;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_9 ) ;
if ( ! V_4 )
goto V_36;
}
V_25 = - V_26 ;
V_36:
F_8 ( V_34 ) ;
F_8 ( V_4 ) ;
return V_25 ;
}
static int
F_28 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 ;
int V_25 , V_42 ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , V_1 -> V_14 ) ;
if ( ! V_4 )
goto V_36;
V_25 = - V_43 ;
for ( V_42 = F_29 ( V_6 ) -> V_44 - 1 ; V_42 >= 0 ; V_42 -- )
if ( F_7 ( V_4 ) -> V_16 [ V_42 ] )
goto V_45;
V_25 = 0 ;
V_45:
F_8 ( V_4 ) ;
V_36:
return V_25 ;
}
int
F_30 ( struct V_28 * V_28 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 , * V_2 ;
struct V_3 * V_4 = NULL ;
int V_25 ;
V_2 = V_28 -> V_46 -> V_33 ;
V_6 = V_2 -> V_7 ;
V_25 = - V_26 ;
V_1 = V_28 -> V_33 ;
if ( ! V_1 )
goto V_36;
F_4 ( L_4 , V_1 -> V_14 ) ;
V_25 = - V_15 ;
V_4 = F_5 ( V_6 , ( T_1 ) ( long ) V_28 -> V_32 ) ;
if ( ! V_4 )
goto V_36;
F_31 ( V_1 ) ;
F_23 ( V_2 ) ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_39 ) ) {
case V_47 :
F_23 ( V_1 ) ;
V_25 = F_28 ( V_1 ) ;
F_24 ( V_1 ) ;
if ( V_25 )
goto V_48;
break;
default:
break;
}
V_25 = F_14 ( V_2 , V_4 ) ;
if ( V_25 )
goto V_48;
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
if ( V_1 -> V_49 > 1 )
V_25 = F_19 ( V_28 ) ;
else
F_32 ( V_1 ) ;
F_33 ( V_1 ) ;
V_1 -> V_20 = V_21 ;
F_13 ( V_1 ) ;
V_36:
F_8 ( V_4 ) ;
return V_25 ;
V_48:
F_24 ( V_2 ) ;
F_33 ( V_1 ) ;
goto V_36;
}
T_1
F_34 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
T_2 * V_50 = ( T_2 * ) V_4 -> V_51 ;
T_1 V_52 ;
int V_53 ;
V_52 = 0 ;
for ( V_53 = V_6 -> V_54 / sizeof( T_2 ) ; V_53 > 0 ; V_53 -- )
V_52 += F_6 ( * V_50 ++ ) ;
return V_52 ;
}
void
F_10 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_55 = V_6 -> V_54 / sizeof( T_2 ) ;
T_2 * V_50 = ( T_2 * ) V_4 -> V_51 ;
T_1 V_56 ;
T_2 * V_57 ;
V_57 = V_50 + 5 ;
* V_57 = 0 ;
for ( V_56 = 0 ; V_55 > 0 ; V_50 ++ , V_55 -- )
V_56 += F_6 ( * V_50 ) ;
* V_57 = F_9 ( - V_56 ) ;
}
void
F_35 ( T_3 V_58 , struct V_59 * V_60 )
{
T_1 V_61 ;
T_1 V_62 ;
V_58 -= V_63 . V_64 * 60 + ( ( 8 * 365 + 2 ) * 24 * 60 * 60 ) ;
if ( V_58 < 0 )
V_58 = 0 ;
V_61 = V_58 / 86400 ;
V_58 -= V_61 * 86400 ;
V_62 = V_58 / 60 ;
V_58 -= V_62 * 60 ;
V_60 -> V_61 = F_9 ( V_61 ) ;
V_60 -> V_65 = F_9 ( V_62 ) ;
V_60 -> V_66 = F_9 ( V_58 * 50 ) ;
}
T_4
F_36 ( T_1 V_67 )
{
T_4 V_68 = 0 ;
if ( ! ( V_67 & V_69 ) )
V_68 |= V_70 ;
if ( ! ( V_67 & V_71 ) )
V_68 |= V_72 ;
if ( ! ( V_67 & V_73 ) )
V_68 |= V_74 ;
if ( V_67 & V_75 )
V_68 |= V_76 ;
if ( V_67 & V_77 )
V_68 |= V_78 ;
if ( V_67 & V_79 )
V_68 |= V_80 ;
if ( V_67 & V_81 )
V_68 |= V_82 ;
if ( V_67 & V_83 )
V_68 |= V_84 ;
if ( V_67 & V_85 )
V_68 |= V_86 ;
return V_68 ;
}
void
F_37 ( struct V_1 * V_1 )
{
T_1 V_67 = F_38 ( V_1 ) -> V_87 ;
T_4 V_68 = V_1 -> V_88 ;
if ( ! ( V_68 & V_74 ) )
V_67 |= V_73 ;
if ( ! ( V_68 & V_72 ) )
V_67 |= V_71 ;
if ( ! ( V_68 & V_70 ) )
V_67 |= V_69 ;
if ( V_68 & V_80 )
V_67 |= V_79 ;
if ( V_68 & V_78 )
V_67 |= V_77 ;
if ( V_68 & V_76 )
V_67 |= V_75 ;
if ( V_68 & V_86 )
V_67 |= V_85 ;
if ( V_68 & V_84 )
V_67 |= V_83 ;
if ( V_68 & V_82 )
V_67 |= V_81 ;
F_38 ( V_1 ) -> V_87 = V_67 ;
}
void
F_39 ( struct V_5 * V_6 , const char * V_89 , const char * V_90 , ... )
{
T_5 args ;
va_start ( args , V_90 ) ;
vsnprintf ( V_91 , sizeof( V_91 ) , V_90 , args ) ;
va_end ( args ) ;
F_40 ( V_92 L_5 , V_6 -> V_93 ,
V_89 , V_91 ) ;
if ( ! ( V_6 -> V_94 & V_95 ) )
F_40 ( V_96 L_6 ) ;
V_6 -> V_94 |= V_95 ;
}
void
F_41 ( struct V_5 * V_6 , const char * V_89 , const char * V_90 , ... )
{
T_5 args ;
va_start ( args , V_90 ) ;
vsnprintf ( V_91 , sizeof( V_91 ) , V_90 , args ) ;
va_end ( args ) ;
F_40 ( V_96 L_7 , V_6 -> V_93 ,
V_89 , V_91 ) ;
}
int
F_42 ( const unsigned char * V_13 , int V_97 )
{
int V_98 ;
if ( V_97 > 30 )
#ifdef F_43
return - V_99 ;
#else
V_97 = 30 ;
#endif
for ( V_98 = 0 ; V_98 < V_97 ; V_98 ++ ) {
if ( V_13 [ V_98 ] < ' ' || V_13 [ V_98 ] == ':'
|| ( V_13 [ V_98 ] > 0x7e && V_13 [ V_98 ] < 0xa0 ) )
return - V_100 ;
}
return 0 ;
}
int
F_44 ( unsigned char * V_101 , struct V_28 * V_28 )
{
int V_97 = F_45 ( V_28 -> V_102 . V_97 , 30u ) ;
* V_101 ++ = V_97 ;
memcpy ( V_101 , V_28 -> V_102 . V_13 , V_97 ) ;
return V_97 ;
}
