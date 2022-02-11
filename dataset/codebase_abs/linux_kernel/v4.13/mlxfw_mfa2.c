bool F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 < sizeof( V_4 ) )
return false ;
return memcmp ( V_2 -> V_5 , V_4 ,
V_6 ) == 0 ;
}
static bool
F_2 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
T_1 V_13 ;
F_3 (mfa2_file, tlv, idx, multi) {
if ( ! V_12 ) {
F_4 ( L_1 ) ;
return false ;
}
}
return true ;
}
static bool
F_5 ( const struct V_7 * V_8 ,
const struct V_11 * V_14 ,
T_1 V_15 )
{
const struct V_16 * V_17 ;
const struct V_9 * V_10 ;
const struct V_18 * V_19 ;
const struct V_11 * V_12 ;
T_1 V_20 ;
T_1 V_21 ;
int V_22 ;
F_6 ( L_2 , V_15 ) ;
V_10 = F_7 ( V_8 , V_14 ) ;
if ( ! V_10 ) {
F_4 ( L_3 , V_15 ) ;
return false ;
}
if ( ! F_2 ( V_8 , V_10 ) )
return false ;
V_12 = F_8 ( V_8 , V_10 ,
V_23 , 0 ) ;
if ( ! V_12 ) {
F_4 ( L_4 , V_15 ) ;
return false ;
}
V_19 = F_9 ( V_8 , V_12 ) ;
if ( ! V_19 ) {
F_4 ( L_5 , V_15 ) ;
return false ;
}
F_10 ( L_6 , V_24 , 16 , 16 ,
V_19 -> V_19 , F_11 ( V_12 -> V_25 ) , true ) ;
V_22 = F_12 ( V_8 , V_10 ,
V_26 ,
& V_20 ) ;
if ( V_22 )
return false ;
if ( V_20 == 0 ) {
F_4 ( L_7 , V_15 ) ;
return false ;
}
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_12 = F_8 ( V_8 , V_10 ,
V_26 ,
V_21 ) ;
if ( ! V_12 )
return false ;
V_17 = F_13 ( V_8 , V_12 ) ;
if ( ! V_17 ) {
F_4 ( L_8 ,
V_15 ) ;
return false ;
}
F_6 ( L_9 ,
F_11 ( V_17 -> V_27 ) ) ;
}
return true ;
}
static bool
F_14 ( const struct V_7 * V_8 ,
const struct V_11 * V_28 ,
T_1 V_29 )
{
const struct V_30 * V_31 ;
const struct V_9 * V_10 ;
const struct V_11 * V_12 ;
F_6 ( L_10 , V_29 ) ;
V_10 = F_7 ( V_8 , V_28 ) ;
if ( ! V_10 ) {
F_4 ( L_11 , V_29 ) ;
return false ;
}
if ( ! F_2 ( V_8 , V_10 ) )
return false ;
V_12 = F_15 ( V_8 , V_10 ) ;
if ( ! V_12 ) {
F_4 ( L_12 , V_29 ) ;
return false ;
}
V_31 = F_16 ( V_8 , V_12 ) ;
if ( ! V_31 ) {
F_4 ( L_13 ,
V_29 ) ;
return false ;
}
F_6 ( L_14 , F_11 ( V_31 -> V_32 ) ) ;
F_6 ( L_15 ,
( ( V_33 ) F_17 ( V_31 -> V_34 ) << 32 )
| F_17 ( V_31 -> V_35 ) , F_17 ( V_31 -> V_3 ) ) ;
return true ;
}
static bool F_18 ( const struct V_7 * V_8 )
{
const struct V_11 * V_12 ;
T_1 V_13 ;
F_6 ( L_16 ) ;
F_19 (mfa2_file, tlv, idx, mfa2_file->first_dev,
mfa2_file->dev_count) {
if ( ! V_12 ) {
F_4 ( L_17 ) ;
return false ;
}
if ( ! F_5 ( V_8 , V_12 , V_13 ) )
return false ;
}
F_19 (mfa2_file, tlv, idx, mfa2_file->first_component,
mfa2_file->component_count) {
if ( ! V_12 ) {
F_4 ( L_17 ) ;
return false ;
}
if ( ! F_14 ( V_8 , V_12 , V_13 ) )
return false ;
}
return true ;
}
struct V_7 * F_20 ( const struct V_1 * V_2 )
{
const struct V_36 * V_37 ;
const struct V_9 * V_10 ;
const struct V_11 * V_38 ;
const struct V_11 * V_39 ;
struct V_7 * V_8 ;
const void * V_40 ;
const void * V_41 ;
V_8 = F_21 ( 1 , sizeof( * V_8 ) , V_42 ) ;
if ( ! V_8 )
return F_22 ( - V_43 ) ;
V_8 -> V_2 = V_2 ;
V_40 = V_2 -> V_5 + F_23 ( V_6 ) ;
V_39 = F_24 ( V_8 , V_40 ) ;
if ( ! V_39 ) {
F_4 ( L_18 ) ;
goto V_44;
}
V_10 = F_7 ( V_8 , V_39 ) ;
if ( ! V_10 ) {
F_4 ( L_19 ) ;
goto V_44;
}
V_38 = F_15 ( V_8 , V_10 ) ;
if ( ! V_38 )
goto V_44;
V_37 = F_25 ( V_8 , V_38 ) ;
if ( ! V_37 ) {
F_4 ( L_18 ) ;
goto V_44;
}
V_8 -> V_45 = F_26 ( V_8 , V_39 ) ;
if ( ! V_8 -> V_45 ) {
F_4 ( L_20 ) ;
goto V_44;
}
V_8 -> V_46 = F_11 ( V_37 -> V_47 ) ;
V_8 -> V_48 = F_27 ( V_8 ,
V_8 -> V_45 ,
V_8 -> V_46 ) ;
V_8 -> V_49 = F_11 ( V_37 -> V_50 ) ;
V_8 -> V_51 = V_2 -> V_5 + F_23 ( F_17 ( V_37 -> V_52 ) ) ;
if ( ! F_28 ( V_8 , V_8 -> V_51 ) ) {
F_4 ( L_21 ) ;
goto V_44;
}
V_8 -> V_53 = F_17 ( V_37 -> V_53 ) ;
V_41 = V_8 -> V_51 + V_8 -> V_53 - 1 ;
if ( ! F_28 ( V_8 , V_41 ) ) {
F_4 ( L_22 ) ;
goto V_44;
}
if ( ! F_18 ( V_8 ) )
goto V_44;
return V_8 ;
V_44:
F_29 ( V_8 ) ;
return F_22 ( - V_54 ) ;
}
static const struct V_9 *
F_30 ( const struct V_7 * V_8 ,
const char * V_19 , T_1 V_55 )
{
const struct V_18 * V_56 ;
const struct V_9 * V_57 ;
const struct V_11 * V_14 ;
const struct V_11 * V_12 ;
T_2 V_13 ;
F_19 (mfa2_file, dev_tlv, idx, mfa2_file->first_dev,
mfa2_file->dev_count) {
if ( ! V_14 )
return NULL ;
V_57 = F_7 ( V_8 , V_14 ) ;
if ( ! V_57 )
return NULL ;
V_12 = F_8 ( V_8 , V_57 ,
V_23 , 0 ) ;
if ( ! V_12 )
return NULL ;
if ( F_11 ( V_12 -> V_25 ) != V_55 )
continue;
V_56 = F_9 ( V_8 , V_12 ) ;
if ( ! V_56 )
return NULL ;
if ( memcmp ( V_19 , V_56 -> V_19 , V_55 ) == 0 )
return V_57 ;
}
return NULL ;
}
int F_31 ( const struct V_7 * V_8 ,
const char * V_19 , T_2 V_55 ,
T_2 * V_58 )
{
const struct V_9 * V_57 ;
T_1 V_59 ;
int V_22 ;
V_57 = F_30 ( V_8 , V_19 , V_55 ) ;
if ( ! V_57 )
return - V_54 ;
V_22 = F_12 ( V_8 , V_57 ,
V_26 ,
& V_59 ) ;
if ( V_22 )
return V_22 ;
* V_58 = V_59 ;
return 0 ;
}
static int F_32 ( struct V_60 * V_60 , struct V_61 * V_61 ,
bool * V_62 )
{
enum V_63 V_63 ;
V_63 = F_33 ( V_60 , V_61 ) ;
switch ( V_63 ) {
case V_64 :
* V_62 = true ;
return 0 ;
case V_65 :
* V_62 = false ;
return 0 ;
case V_66 :
F_4 ( L_23 ) ;
return - V_43 ;
case V_67 :
F_4 ( L_24 ) ;
return - V_54 ;
case V_68 :
F_4 ( L_25 ) ;
return - V_54 ;
case V_69 :
F_4 ( L_26 ) ;
return - V_54 ;
case V_70 :
F_4 ( L_27 ) ;
return - V_54 ;
default:
F_4 ( L_28 , V_63 ) ;
return - V_54 ;
}
}
static int F_34 ( const struct V_7 * V_8 ,
T_3 V_71 , T_4 V_3 , T_5 * V_72 )
{
struct V_60 * V_60 ;
struct V_61 V_73 ;
T_3 V_74 = 0 ;
bool V_62 ;
int V_22 ;
V_60 = F_35 ( V_75 , ( T_2 ) - 1 ) ;
if ( ! V_60 )
return - V_54 ;
V_73 . V_76 = V_8 -> V_53 ;
V_73 . V_77 = V_8 -> V_51 ;
V_73 . V_78 = 0 ;
V_73 . V_79 = V_72 ;
do {
V_73 . V_80 = 0 ;
V_73 . V_81 = F_36 ( T_4 , V_3 , V_71 - V_74 ) ;
if ( V_73 . V_81 == 0 )
break;
V_22 = F_32 ( V_60 , & V_73 , & V_62 ) ;
if ( V_22 )
goto V_79;
if ( V_62 ) {
F_4 ( L_29 ) ;
V_22 = - V_54 ;
goto V_79;
}
V_74 += V_73 . V_80 ;
} while ( V_74 != V_71 );
V_73 . V_80 = 0 ;
V_73 . V_81 = V_3 ;
V_22 = F_32 ( V_60 , & V_73 , & V_62 ) ;
V_79:
F_37 ( V_60 ) ;
return V_22 ;
}
static const struct V_30 *
F_38 ( const struct V_7 * V_8 ,
T_1 V_82 )
{
const struct V_9 * V_10 ;
const struct V_11 * V_38 ;
const struct V_11 * V_28 ;
if ( V_82 > V_8 -> V_49 )
return NULL ;
V_28 = F_27 ( V_8 , V_8 -> V_48 ,
V_82 ) ;
if ( ! V_28 )
return NULL ;
V_10 = F_7 ( V_8 , V_28 ) ;
if ( ! V_10 )
return NULL ;
V_38 = F_15 ( V_8 , V_10 ) ;
if ( ! V_38 )
return NULL ;
return F_16 ( V_8 , V_38 ) ;
}
static const struct V_30 *
F_39 ( const struct V_7 * V_8 ,
const char * V_19 , int V_55 ,
int V_27 )
{
const struct V_16 * V_17 ;
const struct V_9 * V_57 ;
const struct V_11 * V_83 ;
T_1 V_29 ;
V_57 = F_30 ( V_8 , V_19 , V_55 ) ;
if ( ! V_57 )
return NULL ;
V_83 = F_8 ( V_8 , V_57 ,
V_26 ,
V_27 ) ;
if ( ! V_83 )
return NULL ;
V_17 = F_13 ( V_8 , V_83 ) ;
if ( ! V_17 )
return NULL ;
V_29 = F_11 ( V_17 -> V_27 ) ;
return F_38 ( V_8 , V_29 ) ;
}
struct V_84 *
F_40 ( const struct V_7 * V_8 ,
const char * V_19 , int V_55 ,
int V_27 )
{
const struct V_30 * V_85 ;
struct V_86 * V_87 ;
T_2 V_88 ;
T_3 V_52 ;
T_2 V_89 ;
int V_22 ;
V_85 = F_39 ( V_8 , V_19 , V_55 ,
V_27 ) ;
if ( ! V_85 )
return F_22 ( - V_54 ) ;
V_52 = ( V_33 ) F_17 ( V_85 -> V_34 ) << 32 |
F_17 ( V_85 -> V_35 ) ;
V_89 = F_17 ( V_85 -> V_3 ) ;
V_88 = V_89 + V_90 ;
V_87 = F_41 ( sizeof( * V_87 ) + V_88 , V_42 ) ;
if ( ! V_87 )
return F_22 ( - V_43 ) ;
V_87 -> V_85 . V_91 = V_89 ;
V_87 -> V_85 . V_92 = F_11 ( V_85 -> V_32 ) ;
V_22 = F_34 ( V_8 , V_52 , V_88 ,
V_87 -> V_93 ) ;
if ( V_22 ) {
F_4 ( L_30 ) ;
goto V_44;
}
if ( memcmp ( V_87 -> V_93 , V_94 ,
V_90 ) != 0 ) {
F_4 ( L_31 ) ;
V_22 = - V_54 ;
goto V_44;
}
V_87 -> V_85 . V_5 = V_87 -> V_93 + V_90 ;
return & V_87 -> V_85 ;
V_44:
F_29 ( V_87 ) ;
return F_22 ( V_22 ) ;
}
void F_42 ( struct V_84 * V_85 )
{
const struct V_86 * V_87 ;
V_87 = F_43 ( V_85 , struct V_86 , V_85 ) ;
F_29 ( V_87 ) ;
}
void F_44 ( struct V_7 * V_8 )
{
F_29 ( V_8 ) ;
}
