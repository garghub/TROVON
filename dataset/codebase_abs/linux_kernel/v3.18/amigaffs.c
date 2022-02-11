int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_8 ;
T_1 V_9 , V_10 ;
int V_11 ;
V_9 = V_4 -> V_12 ;
V_11 = F_2 ( V_6 , F_3 ( V_6 , V_4 ) -> V_13 + 1 , F_3 ( V_6 , V_4 ) -> V_13 [ 0 ] ) ;
F_4 ( L_1 , V_14 , ( T_1 ) V_2 -> V_15 , V_9 ) ;
V_8 = F_5 ( V_6 , V_2 -> V_15 ) ;
if ( ! V_8 )
return - V_16 ;
V_10 = F_6 ( F_7 ( V_8 ) -> V_17 [ V_11 ] ) ;
while ( V_10 ) {
F_8 ( V_8 ) ;
V_8 = F_5 ( V_6 , V_10 ) ;
if ( ! V_8 )
return - V_16 ;
V_10 = F_6 ( F_3 ( V_6 , V_8 ) -> V_18 ) ;
}
F_3 ( V_6 , V_4 ) -> V_19 = F_9 ( V_2 -> V_15 ) ;
F_3 ( V_6 , V_4 ) -> V_18 = 0 ;
F_10 ( V_6 , V_4 ) ;
if ( V_2 -> V_15 == V_8 -> V_12 )
F_7 ( V_8 ) -> V_17 [ V_11 ] = F_9 ( V_9 ) ;
else
F_3 ( V_6 , V_8 ) -> V_18 = F_9 ( V_9 ) ;
F_11 ( V_8 , V_9 ) ;
F_12 ( V_8 , V_2 ) ;
F_8 ( V_8 ) ;
V_2 -> V_20 = V_2 -> V_21 = V_22 ;
V_2 -> V_23 ++ ;
F_13 ( V_2 ) ;
return 0 ;
}
int
F_14 ( struct V_1 * V_2 , struct V_3 * V_24 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_1 V_25 , V_10 ;
T_2 V_9 ;
int V_11 , V_26 ;
V_6 = V_2 -> V_7 ;
V_25 = V_24 -> V_12 ;
V_11 = F_2 ( V_6 , F_3 ( V_6 , V_24 ) -> V_13 + 1 , F_3 ( V_6 , V_24 ) -> V_13 [ 0 ] ) ;
F_4 ( L_2 ,
V_14 , ( T_1 ) V_2 -> V_15 , V_25 , V_11 ) ;
V_4 = F_5 ( V_6 , V_2 -> V_15 ) ;
if ( ! V_4 )
return - V_16 ;
V_26 = - V_27 ;
V_10 = F_6 ( F_7 ( V_4 ) -> V_17 [ V_11 ] ) ;
while ( V_10 ) {
if ( V_10 == V_25 ) {
V_9 = F_3 ( V_6 , V_24 ) -> V_18 ;
if ( V_2 -> V_15 == V_4 -> V_12 )
F_7 ( V_4 ) -> V_17 [ V_11 ] = V_9 ;
else
F_3 ( V_6 , V_4 ) -> V_18 = V_9 ;
F_11 ( V_4 , F_6 ( V_9 ) - V_10 ) ;
F_12 ( V_4 , V_2 ) ;
F_3 ( V_6 , V_24 ) -> V_19 = 0 ;
V_26 = 0 ;
break;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_10 ) ;
if ( ! V_4 )
return - V_16 ;
V_10 = F_6 ( F_3 ( V_6 , V_4 ) -> V_18 ) ;
}
F_8 ( V_4 ) ;
V_2 -> V_20 = V_2 -> V_21 = V_22 ;
V_2 -> V_23 ++ ;
F_13 ( V_2 ) ;
return V_26 ;
}
static void
F_15 ( struct V_1 * V_1 , T_1 V_28 )
{
struct V_29 * V_29 ;
F_16 ( & V_1 -> V_30 ) ;
F_17 (dentry, &inode->i_dentry, d_alias) {
if ( V_28 == ( T_1 ) ( long ) V_29 -> V_31 ) {
V_29 -> V_31 = ( void * ) V_1 -> V_15 ;
break;
}
}
F_18 ( & V_1 -> V_30 ) ;
}
static int
F_19 ( struct V_29 * V_29 )
{
struct V_1 * V_2 , * V_1 = V_29 -> V_32 ;
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 = NULL , * V_33 = NULL ;
T_1 V_34 , V_9 ;
int V_26 ;
F_4 ( L_3 , V_14 , V_1 -> V_15 ) ;
V_26 = - V_16 ;
V_4 = F_5 ( V_6 , V_1 -> V_15 ) ;
if ( ! V_4 )
goto V_35;
V_34 = ( T_1 ) ( long ) V_29 -> V_31 ;
if ( V_1 -> V_15 == V_34 ) {
V_34 = F_6 ( F_3 ( V_6 , V_4 ) -> V_36 ) ;
V_33 = F_5 ( V_6 , V_34 ) ;
if ( ! V_33 )
goto V_35;
V_2 = F_20 ( V_6 , F_6 ( F_3 ( V_6 , V_33 ) -> V_19 ) ) ;
if ( F_21 ( V_2 ) ) {
V_26 = F_22 ( V_2 ) ;
goto V_35;
}
F_23 ( V_2 ) ;
F_15 ( V_1 , V_34 ) ;
V_26 = F_14 ( V_2 , V_33 ) ;
if ( V_26 ) {
F_24 ( V_2 ) ;
goto V_35;
}
F_12 ( V_33 , V_1 ) ;
memcpy ( F_3 ( V_6 , V_4 ) -> V_13 , F_3 ( V_6 , V_33 ) -> V_13 , 32 ) ;
V_26 = F_1 ( V_2 , V_4 ) ;
if ( V_26 ) {
F_24 ( V_2 ) ;
goto V_35;
}
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
} else {
V_33 = F_5 ( V_6 , V_34 ) ;
if ( ! V_33 )
goto V_35;
}
while ( ( V_9 = F_6 ( F_3 ( V_6 , V_4 ) -> V_36 ) ) != 0 ) {
if ( V_9 == V_34 ) {
T_2 V_37 = F_3 ( V_6 , V_33 ) -> V_36 ;
F_3 ( V_6 , V_4 ) -> V_36 = V_37 ;
F_11 ( V_4 , F_6 ( V_37 ) - V_34 ) ;
F_12 ( V_4 , V_1 ) ;
V_26 = 0 ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_38 ) ) {
case V_39 :
case V_40 :
break;
default:
if ( ! F_3 ( V_6 , V_4 ) -> V_36 )
F_26 ( V_1 , 1 ) ;
}
F_27 ( V_6 , V_34 ) ;
goto V_35;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_9 ) ;
if ( ! V_4 )
goto V_35;
}
V_26 = - V_27 ;
V_35:
F_8 ( V_33 ) ;
F_8 ( V_4 ) ;
return V_26 ;
}
static int
F_28 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 ;
int V_26 , V_41 ;
V_26 = - V_16 ;
V_4 = F_5 ( V_6 , V_1 -> V_15 ) ;
if ( ! V_4 )
goto V_35;
V_26 = - V_42 ;
for ( V_41 = F_29 ( V_6 ) -> V_43 - 1 ; V_41 >= 0 ; V_41 -- )
if ( F_7 ( V_4 ) -> V_17 [ V_41 ] )
goto V_44;
V_26 = 0 ;
V_44:
F_8 ( V_4 ) ;
V_35:
return V_26 ;
}
int
F_30 ( struct V_29 * V_29 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 , * V_2 ;
struct V_3 * V_4 = NULL ;
int V_26 ;
V_2 = V_29 -> V_45 -> V_32 ;
V_6 = V_2 -> V_7 ;
V_26 = - V_27 ;
V_1 = V_29 -> V_32 ;
if ( ! V_1 )
goto V_35;
F_4 ( L_3 , V_14 , V_1 -> V_15 ) ;
V_26 = - V_16 ;
V_4 = F_5 ( V_6 , ( T_1 ) ( long ) V_29 -> V_31 ) ;
if ( ! V_4 )
goto V_35;
F_31 ( V_1 ) ;
F_23 ( V_2 ) ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_38 ) ) {
case V_46 :
F_23 ( V_1 ) ;
V_26 = F_28 ( V_1 ) ;
F_24 ( V_1 ) ;
if ( V_26 )
goto V_47;
break;
default:
break;
}
V_26 = F_14 ( V_2 , V_4 ) ;
if ( V_26 )
goto V_47;
F_12 ( V_4 , V_1 ) ;
F_24 ( V_2 ) ;
if ( V_1 -> V_48 > 1 )
V_26 = F_19 ( V_29 ) ;
else
F_32 ( V_1 ) ;
F_33 ( V_1 ) ;
V_1 -> V_21 = V_22 ;
F_13 ( V_1 ) ;
V_35:
F_8 ( V_4 ) ;
return V_26 ;
V_47:
F_24 ( V_2 ) ;
F_33 ( V_1 ) ;
goto V_35;
}
T_1
F_34 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
T_2 * V_49 = ( T_2 * ) V_4 -> V_50 ;
T_1 V_51 ;
int V_52 ;
V_51 = 0 ;
for ( V_52 = V_6 -> V_53 / sizeof( T_2 ) ; V_52 > 0 ; V_52 -- )
V_51 += F_6 ( * V_49 ++ ) ;
return V_51 ;
}
void
F_10 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_54 = V_6 -> V_53 / sizeof( T_2 ) ;
T_2 * V_49 = ( T_2 * ) V_4 -> V_50 ;
T_1 V_55 ;
T_2 * V_56 ;
V_56 = V_49 + 5 ;
* V_56 = 0 ;
for ( V_55 = 0 ; V_54 > 0 ; V_49 ++ , V_54 -- )
V_55 += F_6 ( * V_49 ) ;
* V_56 = F_9 ( - V_55 ) ;
}
void
F_35 ( T_3 V_57 , struct V_58 * V_59 )
{
T_1 V_60 ;
T_1 V_61 ;
V_57 -= V_62 . V_63 * 60 + ( ( 8 * 365 + 2 ) * 24 * 60 * 60 ) ;
if ( V_57 < 0 )
V_57 = 0 ;
V_60 = V_57 / 86400 ;
V_57 -= V_60 * 86400 ;
V_61 = V_57 / 60 ;
V_57 -= V_61 * 60 ;
V_59 -> V_60 = F_9 ( V_60 ) ;
V_59 -> V_64 = F_9 ( V_61 ) ;
V_59 -> V_65 = F_9 ( V_57 * 50 ) ;
}
T_4
F_36 ( T_1 V_66 )
{
T_4 V_67 = 0 ;
if ( ! ( V_66 & V_68 ) )
V_67 |= V_69 ;
if ( ! ( V_66 & V_70 ) )
V_67 |= V_71 ;
if ( ! ( V_66 & V_72 ) )
V_67 |= V_73 ;
if ( V_66 & V_74 )
V_67 |= V_75 ;
if ( V_66 & V_76 )
V_67 |= V_77 ;
if ( V_66 & V_78 )
V_67 |= V_79 ;
if ( V_66 & V_80 )
V_67 |= V_81 ;
if ( V_66 & V_82 )
V_67 |= V_83 ;
if ( V_66 & V_84 )
V_67 |= V_85 ;
return V_67 ;
}
void
F_37 ( struct V_1 * V_1 )
{
T_1 V_66 = F_38 ( V_1 ) -> V_86 ;
T_4 V_67 = V_1 -> V_87 ;
if ( ! ( V_67 & V_73 ) )
V_66 |= V_72 ;
if ( ! ( V_67 & V_71 ) )
V_66 |= V_70 ;
if ( ! ( V_67 & V_69 ) )
V_66 |= V_68 ;
if ( V_67 & V_79 )
V_66 |= V_78 ;
if ( V_67 & V_77 )
V_66 |= V_76 ;
if ( V_67 & V_75 )
V_66 |= V_74 ;
if ( V_67 & V_85 )
V_66 |= V_84 ;
if ( V_67 & V_83 )
V_66 |= V_82 ;
if ( V_67 & V_81 )
V_66 |= V_80 ;
F_38 ( V_1 ) -> V_86 = V_66 ;
}
void
F_39 ( struct V_5 * V_6 , const char * V_88 , const char * V_89 , ... )
{
T_5 args ;
va_start ( args , V_89 ) ;
vsnprintf ( V_90 , sizeof( V_90 ) , V_89 , args ) ;
va_end ( args ) ;
F_40 ( L_4 , V_6 -> V_91 ,
V_88 , V_90 ) ;
if ( ! ( V_6 -> V_92 & V_93 ) )
F_41 ( L_5 ) ;
V_6 -> V_92 |= V_93 ;
}
void
F_42 ( struct V_5 * V_6 , const char * V_88 , const char * V_89 , ... )
{
T_5 args ;
va_start ( args , V_89 ) ;
vsnprintf ( V_90 , sizeof( V_90 ) , V_89 , args ) ;
va_end ( args ) ;
F_41 ( L_6 , V_6 -> V_91 ,
V_88 , V_90 ) ;
}
bool
F_43 ( const struct V_29 * V_29 )
{
struct V_1 * V_1 = V_29 -> V_32 ;
return F_29 ( V_1 -> V_7 ) -> V_92 & V_94 ;
}
int
F_44 ( const unsigned char * V_13 , int V_95 , bool V_96 )
{
int V_97 ;
if ( V_95 > 30 ) {
if ( V_96 )
return - V_98 ;
else
V_95 = 30 ;
}
for ( V_97 = 0 ; V_97 < V_95 ; V_97 ++ ) {
if ( V_13 [ V_97 ] < ' ' || V_13 [ V_97 ] == ':'
|| ( V_13 [ V_97 ] > 0x7e && V_13 [ V_97 ] < 0xa0 ) )
return - V_99 ;
}
return 0 ;
}
int
F_45 ( unsigned char * V_100 , struct V_29 * V_29 )
{
int V_95 = F_46 ( V_29 -> V_101 . V_95 , 30u ) ;
* V_100 ++ = V_95 ;
memcpy ( V_100 , V_29 -> V_101 . V_13 , V_95 ) ;
return V_95 ;
}
