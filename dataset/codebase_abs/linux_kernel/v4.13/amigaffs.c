int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_8 ;
T_1 V_9 , V_10 ;
int V_11 ;
V_9 = V_4 -> V_12 ;
V_11 = F_2 ( V_6 , F_3 ( V_6 , V_4 ) -> V_13 + 1 , F_3 ( V_6 , V_4 ) -> V_13 [ 0 ] ) ;
F_4 ( L_1 , V_14 , V_2 -> V_15 , V_9 ) ;
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
V_2 -> V_20 = V_2 -> V_21 = F_13 ( V_2 ) ;
V_2 -> V_22 ++ ;
F_14 ( V_2 ) ;
return 0 ;
}
int
F_15 ( struct V_1 * V_2 , struct V_3 * V_23 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
T_1 V_24 , V_10 ;
T_2 V_9 ;
int V_11 , V_25 ;
V_6 = V_2 -> V_7 ;
V_24 = V_23 -> V_12 ;
V_11 = F_2 ( V_6 , F_3 ( V_6 , V_23 ) -> V_13 + 1 , F_3 ( V_6 , V_23 ) -> V_13 [ 0 ] ) ;
F_4 ( L_2 , V_14 , V_2 -> V_15 ,
V_24 , V_11 ) ;
V_4 = F_5 ( V_6 , V_2 -> V_15 ) ;
if ( ! V_4 )
return - V_16 ;
V_25 = - V_26 ;
V_10 = F_6 ( F_7 ( V_4 ) -> V_17 [ V_11 ] ) ;
while ( V_10 ) {
if ( V_10 == V_24 ) {
V_9 = F_3 ( V_6 , V_23 ) -> V_18 ;
if ( V_2 -> V_15 == V_4 -> V_12 )
F_7 ( V_4 ) -> V_17 [ V_11 ] = V_9 ;
else
F_3 ( V_6 , V_4 ) -> V_18 = V_9 ;
F_11 ( V_4 , F_6 ( V_9 ) - V_10 ) ;
F_12 ( V_4 , V_2 ) ;
F_3 ( V_6 , V_23 ) -> V_19 = 0 ;
V_25 = 0 ;
break;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_10 ) ;
if ( ! V_4 )
return - V_16 ;
V_10 = F_6 ( F_3 ( V_6 , V_4 ) -> V_18 ) ;
}
F_8 ( V_4 ) ;
V_2 -> V_20 = V_2 -> V_21 = F_13 ( V_2 ) ;
V_2 -> V_22 ++ ;
F_14 ( V_2 ) ;
return V_25 ;
}
static void
F_16 ( struct V_1 * V_1 , T_1 V_27 )
{
struct V_28 * V_28 ;
F_17 ( & V_1 -> V_29 ) ;
F_18 (dentry, &inode->i_dentry, d_u.d_alias) {
if ( V_27 == ( T_1 ) ( long ) V_28 -> V_30 ) {
V_28 -> V_30 = ( void * ) V_1 -> V_15 ;
break;
}
}
F_19 ( & V_1 -> V_29 ) ;
}
static int
F_20 ( struct V_28 * V_28 )
{
struct V_1 * V_2 , * V_1 = F_21 ( V_28 ) ;
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 , * V_31 = NULL ;
T_1 V_32 , V_9 ;
int V_25 ;
F_4 ( L_3 , V_14 , V_1 -> V_15 ) ;
V_25 = - V_16 ;
V_4 = F_5 ( V_6 , V_1 -> V_15 ) ;
if ( ! V_4 )
goto V_33;
V_32 = ( T_1 ) ( long ) V_28 -> V_30 ;
if ( V_1 -> V_15 == V_32 ) {
V_32 = F_6 ( F_3 ( V_6 , V_4 ) -> V_34 ) ;
V_31 = F_5 ( V_6 , V_32 ) ;
if ( ! V_31 )
goto V_33;
V_2 = F_22 ( V_6 , F_6 ( F_3 ( V_6 , V_31 ) -> V_19 ) ) ;
if ( F_23 ( V_2 ) ) {
V_25 = F_24 ( V_2 ) ;
goto V_33;
}
F_25 ( V_2 ) ;
F_16 ( V_1 , V_32 ) ;
V_25 = F_15 ( V_2 , V_31 ) ;
if ( V_25 ) {
F_26 ( V_2 ) ;
goto V_33;
}
F_12 ( V_31 , V_1 ) ;
memcpy ( F_3 ( V_6 , V_4 ) -> V_13 , F_3 ( V_6 , V_31 ) -> V_13 , 32 ) ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( V_25 ) {
F_26 ( V_2 ) ;
goto V_33;
}
F_12 ( V_4 , V_1 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
} else {
V_31 = F_5 ( V_6 , V_32 ) ;
if ( ! V_31 )
goto V_33;
}
while ( ( V_9 = F_6 ( F_3 ( V_6 , V_4 ) -> V_34 ) ) != 0 ) {
if ( V_9 == V_32 ) {
T_2 V_35 = F_3 ( V_6 , V_31 ) -> V_34 ;
F_3 ( V_6 , V_4 ) -> V_34 = V_35 ;
F_11 ( V_4 , F_6 ( V_35 ) - V_32 ) ;
F_12 ( V_4 , V_1 ) ;
V_25 = 0 ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_36 ) ) {
case V_37 :
case V_38 :
break;
default:
if ( ! F_3 ( V_6 , V_4 ) -> V_34 )
F_28 ( V_1 , 1 ) ;
}
F_29 ( V_6 , V_32 ) ;
goto V_33;
}
F_8 ( V_4 ) ;
V_4 = F_5 ( V_6 , V_9 ) ;
if ( ! V_4 )
goto V_33;
}
V_25 = - V_26 ;
V_33:
F_8 ( V_31 ) ;
F_8 ( V_4 ) ;
return V_25 ;
}
static int
F_30 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_3 * V_4 ;
int V_25 , V_39 ;
V_25 = - V_16 ;
V_4 = F_5 ( V_6 , V_1 -> V_15 ) ;
if ( ! V_4 )
goto V_33;
V_25 = - V_40 ;
for ( V_39 = F_31 ( V_6 ) -> V_41 - 1 ; V_39 >= 0 ; V_39 -- )
if ( F_7 ( V_4 ) -> V_17 [ V_39 ] )
goto V_42;
V_25 = 0 ;
V_42:
F_8 ( V_4 ) ;
V_33:
return V_25 ;
}
int
F_32 ( struct V_28 * V_28 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 , * V_2 ;
struct V_3 * V_4 = NULL ;
int V_25 ;
V_2 = F_21 ( V_28 -> V_43 ) ;
V_6 = V_2 -> V_7 ;
V_25 = - V_26 ;
V_1 = F_21 ( V_28 ) ;
if ( ! V_1 )
goto V_33;
F_4 ( L_3 , V_14 , V_1 -> V_15 ) ;
V_25 = - V_16 ;
V_4 = F_5 ( V_6 , ( T_1 ) ( long ) V_28 -> V_30 ) ;
if ( ! V_4 )
goto V_33;
F_33 ( V_1 ) ;
F_25 ( V_2 ) ;
switch ( F_6 ( F_3 ( V_6 , V_4 ) -> V_36 ) ) {
case V_44 :
F_25 ( V_1 ) ;
V_25 = F_30 ( V_1 ) ;
F_26 ( V_1 ) ;
if ( V_25 )
goto V_45;
break;
default:
break;
}
V_25 = F_15 ( V_2 , V_4 ) ;
if ( V_25 )
goto V_45;
F_12 ( V_4 , V_1 ) ;
F_26 ( V_2 ) ;
if ( V_1 -> V_46 > 1 )
V_25 = F_20 ( V_28 ) ;
else
F_34 ( V_1 ) ;
F_35 ( V_1 ) ;
V_1 -> V_21 = F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
V_33:
F_8 ( V_4 ) ;
return V_25 ;
V_45:
F_26 ( V_2 ) ;
F_35 ( V_1 ) ;
goto V_33;
}
T_1
F_36 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
T_2 * V_47 = ( T_2 * ) V_4 -> V_48 ;
T_1 V_49 ;
int V_50 ;
V_49 = 0 ;
for ( V_50 = V_6 -> V_51 / sizeof( T_2 ) ; V_50 > 0 ; V_50 -- )
V_49 += F_6 ( * V_47 ++ ) ;
return V_49 ;
}
void
F_10 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_52 = V_6 -> V_51 / sizeof( T_2 ) ;
T_2 * V_47 = ( T_2 * ) V_4 -> V_48 ;
T_1 V_53 ;
T_2 * V_54 ;
V_54 = V_47 + 5 ;
* V_54 = 0 ;
for ( V_53 = 0 ; V_52 > 0 ; V_47 ++ , V_52 -- )
V_53 += F_6 ( * V_47 ) ;
* V_54 = F_9 ( - V_53 ) ;
}
void
F_37 ( T_3 V_55 , struct V_56 * V_57 )
{
T_1 V_58 ;
T_1 V_59 ;
T_4 V_60 ;
V_55 -= V_61 . V_62 * 60 + ( ( 8 * 365 + 2 ) * 24 * 60 * 60 ) ;
if ( V_55 < 0 )
V_55 = 0 ;
V_58 = F_38 ( V_55 , 86400 , & V_60 ) ;
V_59 = V_60 / 60 ;
V_60 -= V_59 * 60 ;
V_57 -> V_58 = F_9 ( V_58 ) ;
V_57 -> V_63 = F_9 ( V_59 ) ;
V_57 -> V_64 = F_9 ( V_60 * 50 ) ;
}
T_5
F_39 ( T_1 V_65 )
{
T_5 V_66 = 0 ;
if ( ! ( V_65 & V_67 ) )
V_66 |= 0200 ;
if ( ! ( V_65 & V_68 ) )
V_66 |= 0400 ;
if ( ! ( V_65 & V_69 ) )
V_66 |= 0100 ;
if ( V_65 & V_70 )
V_66 |= 0020 ;
if ( V_65 & V_71 )
V_66 |= 0040 ;
if ( V_65 & V_72 )
V_66 |= 0010 ;
if ( V_65 & V_73 )
V_66 |= 0002 ;
if ( V_65 & V_74 )
V_66 |= 0004 ;
if ( V_65 & V_75 )
V_66 |= 0001 ;
return V_66 ;
}
void
F_40 ( struct V_1 * V_1 )
{
T_1 V_65 = F_41 ( V_1 ) -> V_76 ;
T_5 V_66 = V_1 -> V_77 ;
if ( ! ( V_66 & 0100 ) )
V_65 |= V_69 ;
if ( ! ( V_66 & 0400 ) )
V_65 |= V_68 ;
if ( ! ( V_66 & 0200 ) )
V_65 |= V_67 ;
if ( V_66 & 0010 )
V_65 |= V_72 ;
if ( V_66 & 0040 )
V_65 |= V_71 ;
if ( V_66 & 0020 )
V_65 |= V_70 ;
if ( V_66 & 0001 )
V_65 |= V_75 ;
if ( V_66 & 0004 )
V_65 |= V_74 ;
if ( V_66 & 0002 )
V_65 |= V_73 ;
F_41 ( V_1 ) -> V_76 = V_65 ;
}
void
F_42 ( struct V_5 * V_6 , const char * V_78 , const char * V_79 , ... )
{
struct V_80 V_81 ;
T_6 args ;
va_start ( args , V_79 ) ;
V_81 . V_79 = V_79 ;
V_81 . V_82 = & args ;
F_43 ( L_4 , V_6 -> V_83 , V_78 , & V_81 ) ;
if ( ! ( V_6 -> V_84 & V_85 ) )
F_44 ( L_5 ) ;
V_6 -> V_84 |= V_85 ;
va_end ( args ) ;
}
void
F_45 ( struct V_5 * V_6 , const char * V_78 , const char * V_79 , ... )
{
struct V_80 V_81 ;
T_6 args ;
va_start ( args , V_79 ) ;
V_81 . V_79 = V_79 ;
V_81 . V_82 = & args ;
F_44 ( L_6 , V_6 -> V_83 , V_78 , & V_81 ) ;
va_end ( args ) ;
}
bool
F_46 ( const struct V_28 * V_28 )
{
return F_47 ( F_31 ( V_28 -> V_86 ) -> V_84 , V_87 ) ;
}
int
F_48 ( const unsigned char * V_13 , int V_88 , bool V_89 )
{
int V_90 ;
if ( V_88 > V_91 ) {
if ( V_89 )
return - V_92 ;
V_88 = V_91 ;
}
for ( V_90 = 0 ; V_90 < V_88 ; V_90 ++ ) {
if ( V_13 [ V_90 ] < ' ' || V_13 [ V_90 ] == ':'
|| ( V_13 [ V_90 ] > 0x7e && V_13 [ V_90 ] < 0xa0 ) )
return - V_93 ;
}
return 0 ;
}
int
F_49 ( unsigned char * V_94 , struct V_28 * V_28 )
{
T_1 V_88 = F_50 ( V_28 -> V_95 . V_88 , V_91 ) ;
* V_94 ++ = V_88 ;
memcpy ( V_94 , V_28 -> V_95 . V_13 , V_88 ) ;
return V_88 ;
}
