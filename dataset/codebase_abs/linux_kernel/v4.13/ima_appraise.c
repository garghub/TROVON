static int T_1 F_1 ( char * V_1 )
{
#ifdef F_2
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 0 ;
else if ( strncmp ( V_1 , L_2 , 3 ) == 0 )
V_2 = V_3 ;
else if ( strncmp ( V_1 , L_3 , 3 ) == 0 )
V_2 = V_4 ;
#endif
return 1 ;
}
bool F_3 ( void )
{
return ( V_2 & V_5 ) ? 1 : 0 ;
}
int F_4 ( struct V_6 * V_6 , int V_7 , enum V_8 V_9 )
{
if ( ! V_2 )
return 0 ;
return F_5 ( V_6 , V_9 , V_7 , V_10 , NULL ) ;
}
static int F_6 ( struct V_11 * V_11 ,
struct V_12 * V_13 )
{
int V_14 , V_15 ;
T_2 V_16 = V_13 -> V_17 -> V_16 ;
if ( V_16 <= V_18 ) {
V_15 = 1 ;
V_13 -> V_17 -> V_19 . V_20 . type = V_21 ;
} else {
V_15 = 0 ;
V_13 -> V_17 -> V_19 . V_22 . type = V_23 ;
V_13 -> V_17 -> V_19 . V_22 . V_16 = V_16 ;
}
V_14 = F_7 ( V_11 , V_24 ,
& V_13 -> V_17 -> V_19 . V_25 [ V_15 ] ,
( sizeof( V_13 -> V_17 -> V_19 ) - V_15 ) +
V_13 -> V_17 -> V_26 , 0 ) ;
return V_14 ;
}
enum V_27 F_8 ( struct V_12 * V_13 ,
enum V_8 V_9 )
{
switch ( V_9 ) {
case V_28 :
return V_13 -> V_29 ;
case V_30 :
return V_13 -> V_31 ;
case V_32 :
case V_33 :
return V_13 -> V_34 ;
case V_35 ... V_36 - 1 :
default:
return V_13 -> V_37 ;
}
}
static void F_9 ( struct V_12 * V_13 ,
enum V_8 V_9 ,
enum V_27 V_38 )
{
switch ( V_9 ) {
case V_28 :
V_13 -> V_29 = V_38 ;
break;
case V_30 :
V_13 -> V_31 = V_38 ;
break;
case V_32 :
case V_33 :
V_13 -> V_34 = V_38 ;
break;
case V_35 ... V_36 - 1 :
default:
V_13 -> V_37 = V_38 ;
break;
}
}
static void F_10 ( struct V_12 * V_13 ,
enum V_8 V_9 )
{
switch ( V_9 ) {
case V_28 :
V_13 -> V_39 |= ( V_40 | V_41 ) ;
break;
case V_30 :
V_13 -> V_39 |= ( V_42 | V_41 ) ;
break;
case V_32 :
case V_33 :
V_13 -> V_39 |= ( V_43 | V_41 ) ;
break;
case V_35 ... V_36 - 1 :
default:
V_13 -> V_39 |= ( V_44 | V_41 ) ;
break;
}
}
enum V_45 F_11 ( struct V_46 * V_47 ,
int V_48 )
{
struct V_49 * V_50 ;
enum V_45 V_51 ;
if ( ! V_47 || V_48 < 2 )
return V_52 ;
switch ( V_47 -> type ) {
case V_53 :
V_50 = ( F_12 ( V_50 ) ) V_47 ;
if ( V_50 -> V_54 != 2 || V_48 <= sizeof( * V_50 ) )
return V_52 ;
return V_50 -> V_45 ;
break;
case V_23 :
V_51 = V_47 -> V_55 [ 0 ] ;
if ( V_51 < V_56 )
return V_51 ;
break;
case V_21 :
if ( V_48 == 21 ) {
unsigned int V_57 = 0 ;
if ( ! memcmp ( & V_47 -> V_55 [ 16 ] , & V_57 , 4 ) )
return V_58 ;
else
return V_18 ;
} else if ( V_48 == 17 )
return V_58 ;
break;
}
return V_52 ;
}
int F_13 ( struct V_11 * V_11 ,
struct V_46 * * V_47 )
{
T_3 V_51 ;
V_51 = F_14 ( V_11 , V_24 , ( char * * ) V_47 ,
0 , V_59 ) ;
if ( V_51 == - V_60 )
V_51 = 0 ;
return V_51 ;
}
int F_15 ( enum V_8 V_9 ,
struct V_12 * V_13 ,
struct V_61 * V_61 , const unsigned char * V_62 ,
struct V_46 * V_47 ,
int V_48 , int V_63 )
{
static const char V_64 [] = L_4 ;
char * V_65 = L_5 ;
struct V_11 * V_11 = F_16 ( V_61 ) ;
struct V_6 * V_6 = F_17 ( V_11 ) ;
enum V_27 V_38 = V_66 ;
int V_14 = V_48 , V_67 = 0 ;
if ( ! ( V_6 -> V_68 & V_69 ) )
return V_66 ;
if ( V_14 <= 0 ) {
if ( V_14 && V_14 != - V_70 )
goto V_71;
V_65 = V_13 -> V_39 & V_72 ?
L_6 : L_7 ;
V_38 = V_73 ;
if ( V_63 & V_74 )
V_13 -> V_39 |= V_75 ;
if ( ( V_13 -> V_39 & V_75 ) &&
! ( V_13 -> V_39 & V_72 ) )
V_38 = V_76 ;
goto V_71;
}
V_38 = F_18 ( V_11 , V_24 , V_47 , V_14 , V_13 ) ;
if ( ( V_38 != V_76 ) && ( V_38 != V_66 ) ) {
if ( ( V_38 == V_73 )
|| ( V_38 == V_77 ) )
V_65 = L_8 ;
else if ( V_38 == V_78 )
V_65 = L_9 ;
goto V_71;
}
switch ( V_47 -> type ) {
case V_23 :
V_67 = 1 ;
case V_21 :
if ( V_13 -> V_39 & V_72 ) {
V_65 = L_6 ;
V_38 = V_78 ;
break;
}
if ( V_48 - sizeof( V_47 -> type ) - V_67 >=
V_13 -> V_17 -> V_26 )
V_14 = memcmp ( & V_47 -> V_55 [ V_67 ] ,
V_13 -> V_17 -> V_55 ,
V_13 -> V_17 -> V_26 ) ;
else
V_14 = - V_79 ;
if ( V_14 ) {
V_65 = L_10 ;
V_38 = V_78 ;
break;
}
V_38 = V_76 ;
break;
case V_53 :
V_13 -> V_39 |= V_80 ;
V_14 = F_19 ( V_81 ,
( const char * ) V_47 , V_14 ,
V_13 -> V_17 -> V_55 ,
V_13 -> V_17 -> V_26 ) ;
if ( V_14 == - V_60 ) {
V_38 = V_66 ;
} else if ( V_14 ) {
V_65 = L_11 ;
V_38 = V_78 ;
} else {
V_38 = V_76 ;
}
break;
default:
V_38 = V_66 ;
V_65 = L_12 ;
break;
}
V_71:
if ( V_38 != V_76 ) {
if ( ( V_2 & V_4 ) &&
( ! V_47 ||
V_47 -> type != V_53 ) ) {
if ( ! F_6 ( V_11 , V_13 ) )
V_38 = V_76 ;
} else if ( ( V_6 -> V_82 == 0 ) &&
( V_13 -> V_39 & V_75 ) &&
( V_47 &&
V_47 -> type == V_53 ) ) {
V_38 = V_76 ;
}
F_20 ( V_83 , V_6 , V_62 ,
V_64 , V_65 , V_14 , 0 ) ;
} else {
F_10 ( V_13 , V_9 ) ;
}
F_9 ( V_13 , V_9 , V_38 ) ;
return V_38 ;
}
void F_21 ( struct V_12 * V_13 , struct V_61 * V_61 )
{
struct V_11 * V_11 = F_16 ( V_61 ) ;
int V_14 = 0 ;
if ( V_13 -> V_39 & V_80 )
return;
V_14 = F_22 ( V_13 , V_61 , NULL , 0 , V_52 ) ;
if ( V_14 < 0 )
return;
F_6 ( V_11 , V_13 ) ;
}
void F_23 ( struct V_11 * V_11 )
{
struct V_6 * V_6 = F_17 ( V_11 ) ;
struct V_12 * V_13 ;
int V_84 ;
if ( ! ( V_85 & V_10 ) || ! F_24 ( V_6 -> V_86 )
|| ! ( V_6 -> V_68 & V_69 ) )
return;
V_84 = F_4 ( V_6 , V_87 , V_33 ) ;
V_13 = F_25 ( V_6 ) ;
if ( V_13 ) {
V_13 -> V_39 &= ~ ( V_10 | V_41 |
V_88 | V_89 |
V_90 ) ;
if ( V_84 )
V_13 -> V_39 |= V_10 ;
}
if ( ! V_84 )
F_26 ( V_11 , V_24 ) ;
}
static int F_27 ( struct V_11 * V_11 , const char * V_91 ,
const void * V_47 , T_4 V_92 )
{
if ( strcmp ( V_91 , V_24 ) == 0 ) {
if ( ! F_28 ( V_93 ) )
return - V_94 ;
return 1 ;
}
return 0 ;
}
static void F_29 ( struct V_6 * V_6 , int V_95 )
{
struct V_12 * V_13 ;
if ( ! ( V_85 & V_10 ) || ! F_24 ( V_6 -> V_86 ) )
return;
V_13 = F_25 ( V_6 ) ;
if ( ! V_13 )
return;
V_13 -> V_39 &= ~ V_96 ;
V_13 -> V_97 = 0 ;
if ( V_95 )
V_13 -> V_39 |= V_80 ;
return;
}
int F_30 ( struct V_11 * V_11 , const char * V_91 ,
const void * V_47 , T_4 V_92 )
{
const struct V_46 * V_98 = V_47 ;
int V_99 ;
V_99 = F_27 ( V_11 , V_91 , V_47 ,
V_92 ) ;
if ( V_99 == 1 ) {
if ( ! V_92 || ( V_98 -> type >= V_100 ) )
return - V_79 ;
F_29 ( F_17 ( V_11 ) ,
( V_98 -> type == V_53 ) ? 1 : 0 ) ;
V_99 = 0 ;
}
return V_99 ;
}
int F_31 ( struct V_11 * V_11 , const char * V_91 )
{
int V_99 ;
V_99 = F_27 ( V_11 , V_91 , NULL , 0 ) ;
if ( V_99 == 1 ) {
F_29 ( F_17 ( V_11 ) , 0 ) ;
V_99 = 0 ;
}
return V_99 ;
}
