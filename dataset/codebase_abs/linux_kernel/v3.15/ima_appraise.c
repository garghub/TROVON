static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 0 ;
else if ( strncmp ( V_1 , L_2 , 3 ) == 0 )
V_2 = V_3 ;
return 1 ;
}
int F_2 ( struct V_4 * V_4 , int V_5 , enum V_6 V_7 )
{
if ( ! V_2 )
return 0 ;
return F_3 ( V_4 , V_7 , V_5 , V_8 ) ;
}
static int F_4 ( struct V_9 * V_9 ,
struct V_10 * V_11 )
{
int V_12 , V_13 ;
T_2 V_14 = V_11 -> V_15 -> V_14 ;
if ( V_14 <= V_16 ) {
V_13 = 1 ;
V_11 -> V_15 -> V_17 . V_18 . type = V_19 ;
} else {
V_13 = 0 ;
V_11 -> V_15 -> V_17 . V_20 . type = V_21 ;
V_11 -> V_15 -> V_17 . V_20 . V_14 = V_14 ;
}
V_12 = F_5 ( V_9 , V_22 ,
& V_11 -> V_15 -> V_17 . V_23 [ V_13 ] ,
( sizeof( V_11 -> V_15 -> V_17 ) - V_13 ) +
V_11 -> V_15 -> V_24 , 0 ) ;
return V_12 ;
}
enum V_25 F_6 ( struct V_10 * V_11 ,
int V_7 )
{
switch ( V_7 ) {
case V_26 :
return V_11 -> V_27 ;
case V_28 :
return V_11 -> V_29 ;
case V_30 :
return V_11 -> V_31 ;
case V_32 :
default:
return V_11 -> V_33 ;
}
}
static void F_7 ( struct V_10 * V_11 ,
int V_7 , enum V_25 V_34 )
{
switch ( V_7 ) {
case V_26 :
V_11 -> V_27 = V_34 ;
break;
case V_28 :
V_11 -> V_29 = V_34 ;
break;
case V_30 :
V_11 -> V_31 = V_34 ;
break;
case V_32 :
default:
V_11 -> V_33 = V_34 ;
break;
}
}
static void F_8 ( struct V_10 * V_11 , int V_7 )
{
switch ( V_7 ) {
case V_26 :
V_11 -> V_35 |= ( V_36 | V_37 ) ;
break;
case V_28 :
V_11 -> V_35 |= ( V_38 | V_37 ) ;
break;
case V_30 :
V_11 -> V_35 |= ( V_39 | V_37 ) ;
break;
case V_32 :
default:
V_11 -> V_35 |= ( V_40 | V_37 ) ;
break;
}
}
void F_9 ( struct V_41 * V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
if ( ! V_42 || V_43 < 2 )
return;
switch ( V_42 -> type ) {
case V_48 :
V_47 = ( F_10 ( V_47 ) ) V_42 ;
if ( V_47 -> V_49 != 2 || V_43 <= sizeof( * V_47 ) )
return;
V_45 -> V_14 = V_47 -> V_50 ;
break;
case V_21 :
V_45 -> V_14 = V_42 -> V_51 [ 0 ] ;
break;
case V_19 :
if ( V_43 == 21 ) {
unsigned int V_52 = 0 ;
if ( ! memcmp ( & V_42 -> V_51 [ 16 ] , & V_52 , 4 ) )
V_45 -> V_14 = V_53 ;
else
V_45 -> V_14 = V_16 ;
} else if ( V_43 == 17 )
V_45 -> V_14 = V_53 ;
break;
}
}
int F_11 ( struct V_9 * V_9 ,
struct V_41 * * V_42 )
{
struct V_4 * V_4 = V_9 -> V_54 ;
if ( ! V_4 -> V_55 -> V_56 )
return 0 ;
return F_12 ( V_9 , V_22 , ( char * * ) V_42 ,
0 , V_57 ) ;
}
int F_13 ( int V_7 , struct V_10 * V_11 ,
struct V_58 * V_58 , const unsigned char * V_59 ,
struct V_41 * V_42 ,
int V_43 )
{
static const char V_60 [] = L_3 ;
char * V_61 = L_4 ;
struct V_9 * V_9 = V_58 -> V_62 ;
struct V_4 * V_4 = V_9 -> V_54 ;
enum V_25 V_34 = V_63 ;
int V_12 = V_43 , V_64 = 0 ;
if ( ! V_2 )
return 0 ;
if ( ! V_4 -> V_55 -> V_56 )
return V_63 ;
if ( V_12 <= 0 ) {
if ( V_12 && V_12 != - V_65 )
goto V_66;
V_61 = L_5 ;
V_34 =
( V_4 -> V_67 == 0 ) ? V_68 : V_69 ;
goto V_66;
}
V_34 = F_14 ( V_9 , V_22 , V_42 , V_12 , V_11 ) ;
if ( ( V_34 != V_68 ) && ( V_34 != V_63 ) ) {
if ( ( V_34 == V_69 )
|| ( V_34 == V_70 ) )
V_61 = L_6 ;
else if ( V_34 == V_71 )
V_61 = L_7 ;
goto V_66;
}
switch ( V_42 -> type ) {
case V_21 :
V_64 = 1 ;
case V_19 :
if ( V_11 -> V_35 & V_72 ) {
V_61 = L_8 ;
V_34 = V_71 ;
break;
}
if ( V_43 - sizeof( V_42 -> type ) - V_64 >=
V_11 -> V_15 -> V_24 )
V_12 = memcmp ( & V_42 -> V_51 [ V_64 ] ,
V_11 -> V_15 -> V_51 ,
V_11 -> V_15 -> V_24 ) ;
else
V_12 = - V_73 ;
if ( V_12 ) {
V_61 = L_9 ;
V_34 = V_71 ;
break;
}
V_34 = V_68 ;
break;
case V_48 :
V_11 -> V_35 |= V_74 ;
V_12 = F_15 ( V_75 ,
( const char * ) V_42 , V_12 ,
V_11 -> V_15 -> V_51 ,
V_11 -> V_15 -> V_24 ) ;
if ( V_12 == - V_76 ) {
V_34 = V_63 ;
} else if ( V_12 ) {
V_61 = L_10 ;
V_34 = V_71 ;
} else {
V_34 = V_68 ;
}
break;
default:
V_34 = V_63 ;
V_61 = L_11 ;
break;
}
V_66:
if ( V_34 != V_68 ) {
if ( ( V_2 & V_3 ) &&
( ! V_42 ||
V_42 -> type != V_48 ) ) {
if ( ! F_4 ( V_9 , V_11 ) )
V_34 = V_68 ;
}
F_16 ( V_77 , V_4 , V_59 ,
V_60 , V_61 , V_12 , 0 ) ;
} else {
F_8 ( V_11 , V_7 ) ;
}
F_7 ( V_11 , V_7 , V_34 ) ;
return V_34 ;
}
void F_17 ( struct V_10 * V_11 , struct V_58 * V_58 )
{
struct V_9 * V_9 = V_58 -> V_62 ;
int V_12 = 0 ;
if ( V_11 -> V_35 & V_74 )
return;
V_12 = F_18 ( V_11 , V_58 , NULL , NULL ) ;
if ( V_12 < 0 )
return;
F_4 ( V_9 , V_11 ) ;
}
void F_19 ( struct V_9 * V_9 )
{
struct V_4 * V_4 = V_9 -> V_54 ;
struct V_10 * V_11 ;
int V_78 , V_12 ;
if ( ! V_79 || ! V_2 || ! F_20 ( V_4 -> V_80 )
|| ! V_4 -> V_55 -> V_81 )
return;
V_78 = F_2 ( V_4 , V_82 , V_83 ) ;
V_11 = F_21 ( V_4 ) ;
if ( V_11 ) {
V_11 -> V_35 &= ~ ( V_8 | V_37 |
V_84 | V_85 |
V_86 ) ;
if ( V_78 )
V_11 -> V_35 |= V_8 ;
}
if ( ! V_78 )
V_12 = V_4 -> V_55 -> V_81 ( V_9 , V_22 ) ;
return;
}
static int F_22 ( struct V_9 * V_9 , const char * V_87 ,
const void * V_42 , T_3 V_88 )
{
if ( strcmp ( V_87 , V_22 ) == 0 ) {
if ( ! F_23 ( V_89 ) )
return - V_90 ;
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_4 * V_4 )
{
struct V_10 * V_11 ;
if ( ! V_79 || ! V_2 || ! F_20 ( V_4 -> V_80 ) )
return;
V_11 = F_21 ( V_4 ) ;
if ( ! V_11 )
return;
V_11 -> V_35 &= ~ V_91 ;
return;
}
int F_25 ( struct V_9 * V_9 , const char * V_87 ,
const void * V_42 , T_3 V_88 )
{
int V_92 ;
V_92 = F_22 ( V_9 , V_87 , V_42 ,
V_88 ) ;
if ( V_92 == 1 ) {
F_24 ( V_9 -> V_54 ) ;
V_92 = 0 ;
}
return V_92 ;
}
int F_26 ( struct V_9 * V_9 , const char * V_87 )
{
int V_92 ;
V_92 = F_22 ( V_9 , V_87 , NULL , 0 ) ;
if ( V_92 == 1 ) {
F_24 ( V_9 -> V_54 ) ;
V_92 = 0 ;
}
return V_92 ;
}
