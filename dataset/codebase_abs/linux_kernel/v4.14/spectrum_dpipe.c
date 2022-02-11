static int F_1 ( void * V_1 ,
struct V_2 * V_3 )
{
struct V_4 V_5 = { 0 } ;
int V_6 ;
V_5 . type = V_7 ;
V_5 . V_8 = & V_9 ;
V_5 . V_10 = V_11 ;
V_6 = F_2 ( V_3 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_5 . type = V_7 ;
V_5 . V_8 = & V_9 ;
V_5 . V_10 = V_12 ;
return F_2 ( V_3 , & V_5 ) ;
}
static int F_3 ( void * V_1 ,
struct V_2 * V_3 )
{
struct V_13 V_14 = { 0 } ;
V_14 . type = V_15 ;
V_14 . V_8 = & V_9 ;
V_14 . V_10 = V_16 ;
return F_4 ( V_3 , & V_14 ) ;
}
static void
F_5 ( struct V_13 * V_14 ,
struct V_4 * V_5 )
{
V_5 -> type = V_7 ;
V_5 -> V_8 = & V_9 ;
V_5 -> V_10 = V_11 ;
V_14 -> type = V_15 ;
V_14 -> V_8 = & V_9 ;
V_14 -> V_10 = V_16 ;
}
static int F_6 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
struct V_13 * V_14 ,
struct V_19 * V_21 ,
struct V_4 * V_5 )
{
V_18 -> V_22 = V_20 ;
V_18 -> V_23 = 1 ;
V_18 -> V_24 = V_21 ;
V_18 -> V_25 = 1 ;
V_20 -> V_14 = V_14 ;
V_20 -> V_26 = sizeof( V_27 ) ;
V_20 -> V_28 = F_7 ( V_20 -> V_26 , V_29 ) ;
if ( ! V_20 -> V_28 )
return - V_30 ;
V_21 -> V_5 = V_5 ;
V_21 -> V_26 = sizeof( V_27 ) ;
V_21 -> V_28 = F_7 ( V_21 -> V_26 , V_29 ) ;
if ( ! V_21 -> V_28 )
goto V_31;
return 0 ;
V_31:
F_8 ( V_20 -> V_28 ) ;
return - V_30 ;
}
static int F_9 ( struct V_32 * V_32 ,
struct V_17 * V_18 ,
struct V_33 * V_34 ,
bool V_35 )
{
V_27 * V_21 ;
V_27 * V_36 ;
T_1 V_37 ;
int V_6 ;
V_36 = V_18 -> V_22 -> V_28 ;
* V_36 = F_10 ( V_34 ) ;
V_18 -> V_22 -> V_38 = F_11 ( V_34 ) ;
V_18 -> V_22 -> V_39 = true ;
V_21 = V_18 -> V_24 -> V_28 ;
* V_21 = 1 ;
V_18 -> V_40 = false ;
V_18 -> V_41 = 0 ;
V_18 -> V_42 = F_10 ( V_34 ) ;
if ( ! V_35 )
return 0 ;
V_6 = F_12 ( V_32 , V_34 ,
V_43 ,
& V_37 ) ;
if ( ! V_6 ) {
V_18 -> V_41 = V_37 ;
V_18 -> V_40 = true ;
}
return 0 ;
}
static int
F_13 ( void * V_1 , bool V_35 ,
struct V_44 * V_45 )
{
struct V_19 V_20 , V_21 ;
struct V_4 V_5 = { 0 } ;
struct V_13 V_14 = { 0 } ;
struct V_17 V_18 = { 0 } ;
struct V_32 * V_32 = V_1 ;
unsigned int V_46 ;
int V_47 , V_48 ;
int V_6 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_5 ( & V_14 , & V_5 ) ;
V_6 = F_6 ( & V_18 , & V_20 , & V_14 ,
& V_21 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_46 = F_14 ( V_32 -> V_49 , V_50 ) ;
F_15 () ;
V_47 = 0 ;
V_51:
V_6 = F_16 ( V_45 ) ;
if ( V_6 )
return V_6 ;
V_48 = 0 ;
for (; V_47 < V_46 ; V_47 ++ ) {
struct V_33 * V_34 = F_17 ( V_32 , V_47 ) ;
if ( ! V_34 )
continue;
V_6 = F_9 ( V_32 , & V_18 , V_34 ,
V_35 ) ;
if ( V_6 )
goto V_52;
V_6 = F_18 ( V_45 , & V_18 ) ;
if ( V_6 ) {
if ( V_6 == - V_53 ) {
if ( ! V_48 )
goto V_54;
break;
}
goto V_54;
}
V_48 ++ ;
}
F_19 ( V_45 ) ;
if ( V_47 != V_46 )
goto V_51;
F_20 () ;
F_21 ( & V_18 ) ;
return 0 ;
V_54:
V_52:
F_20 () ;
F_21 ( & V_18 ) ;
return V_6 ;
}
static int F_22 ( void * V_1 , bool V_55 )
{
struct V_32 * V_32 = V_1 ;
int V_47 ;
F_15 () ;
for ( V_47 = 0 ; V_47 < F_14 ( V_32 -> V_49 , V_50 ) ; V_47 ++ ) {
struct V_33 * V_34 = F_17 ( V_32 , V_47 ) ;
if ( ! V_34 )
continue;
if ( V_55 )
F_23 ( V_32 , V_34 ,
V_43 ) ;
else
F_24 ( V_32 , V_34 ,
V_43 ) ;
}
F_20 () ;
return 0 ;
}
static T_1 F_25 ( void * V_1 )
{
struct V_32 * V_32 = V_1 ;
return F_14 ( V_32 -> V_49 , V_50 ) ;
}
static int F_26 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
return F_28 ( V_56 ,
V_57 ,
& V_58 ,
V_32 , false ) ;
}
static void F_29 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
F_30 ( V_56 , V_57 ) ;
}
static int F_31 ( struct V_2 * V_3 , int type )
{
struct V_13 V_14 = { 0 } ;
int V_6 ;
V_14 . type = V_15 ;
V_14 . V_8 = & V_9 ;
V_14 . V_10 = V_16 ;
V_6 = F_4 ( V_3 , & V_14 ) ;
if ( V_6 )
return V_6 ;
switch ( type ) {
case V_59 :
V_14 . type = V_15 ;
V_14 . V_8 = & V_60 ;
V_14 . V_10 = V_61 ;
break;
case V_62 :
V_14 . type = V_15 ;
V_14 . V_8 = & V_63 ;
V_14 . V_10 = V_64 ;
break;
default:
F_32 ( 1 ) ;
return - V_65 ;
}
return F_4 ( V_3 , & V_14 ) ;
}
static int
F_33 ( void * V_1 , struct V_2 * V_3 )
{
return F_31 ( V_3 , V_59 ) ;
}
static int
F_34 ( void * V_1 , struct V_2 * V_3 )
{
struct V_4 V_5 = { 0 } ;
V_5 . type = V_7 ;
V_5 . V_8 = & V_66 ;
V_5 . V_10 = V_67 ;
return F_2 ( V_3 , & V_5 ) ;
}
static void
F_35 ( struct V_13 * V_68 ,
struct V_4 * V_5 ,
int type )
{
struct V_13 * V_14 ;
V_14 = & V_68 [ V_69 ] ;
V_14 -> type = V_15 ;
V_14 -> V_8 = & V_9 ;
V_14 -> V_10 = V_16 ;
V_14 = & V_68 [ V_70 ] ;
V_14 -> type = V_15 ;
switch ( type ) {
case V_59 :
V_14 -> V_8 = & V_60 ;
V_14 -> V_10 = V_61 ;
break;
case V_62 :
V_14 -> V_8 = & V_63 ;
V_14 -> V_10 = V_64 ;
break;
default:
F_32 ( 1 ) ;
return;
}
V_5 -> type = V_7 ;
V_5 -> V_8 = & V_66 ;
V_5 -> V_10 = V_67 ;
}
static int
F_36 ( struct V_17 * V_18 ,
struct V_19 * V_22 ,
struct V_13 * V_68 ,
struct V_19 * V_21 ,
struct V_4 * V_5 ,
int type )
{
struct V_19 * V_20 ;
struct V_13 * V_14 ;
V_18 -> V_22 = V_22 ;
V_18 -> V_23 = V_71 ;
V_18 -> V_24 = V_21 ;
V_18 -> V_25 = 1 ;
V_14 = & V_68 [ V_69 ] ;
V_20 = & V_22 [ V_69 ] ;
V_20 -> V_14 = V_14 ;
V_20 -> V_26 = sizeof( V_27 ) ;
V_20 -> V_28 = F_7 ( V_20 -> V_26 , V_29 ) ;
if ( ! V_20 -> V_28 )
return - V_30 ;
V_14 = & V_68 [ V_70 ] ;
V_20 = & V_22 [ V_70 ] ;
V_20 -> V_14 = V_14 ;
switch ( type ) {
case V_59 :
V_20 -> V_26 = sizeof( V_27 ) ;
break;
case V_62 :
V_20 -> V_26 = sizeof( struct V_72 ) ;
break;
default:
F_32 ( 1 ) ;
return - V_65 ;
}
V_20 -> V_28 = F_7 ( V_20 -> V_26 , V_29 ) ;
if ( ! V_20 -> V_28 )
return - V_30 ;
V_21 -> V_5 = V_5 ;
V_21 -> V_26 = sizeof( T_1 ) ;
V_21 -> V_28 = F_7 ( V_21 -> V_26 , V_29 ) ;
if ( ! V_21 -> V_28 )
return - V_30 ;
return 0 ;
}
static void
F_37 ( struct V_17 * V_18 ,
struct V_33 * V_34 ,
unsigned char * V_73 , void * V_74 )
{
struct V_19 * V_28 ;
V_27 * V_36 ;
T_2 * V_75 ;
V_28 = & V_18 -> V_22 [ V_69 ] ;
V_36 = V_28 -> V_28 ;
* V_36 = F_10 ( V_34 ) ;
V_28 -> V_38 = F_11 ( V_34 ) ;
V_28 -> V_39 = true ;
V_28 = & V_18 -> V_22 [ V_70 ] ;
memcpy ( V_28 -> V_28 , V_74 , V_28 -> V_26 ) ;
V_28 = V_18 -> V_24 ;
V_75 = V_28 -> V_28 ;
F_38 ( V_75 , V_73 ) ;
}
static void
F_39 ( struct V_17 * V_18 ,
struct V_76 * V_77 ,
struct V_33 * V_34 )
{
unsigned char * V_73 ;
V_27 V_74 ;
V_73 = F_40 ( V_77 ) ;
V_74 = F_41 ( V_77 ) ;
F_37 ( V_18 , V_34 , V_73 , & V_74 ) ;
}
static void
F_42 ( struct V_17 * V_18 ,
struct V_76 * V_77 ,
struct V_33 * V_34 )
{
struct V_72 * V_74 ;
unsigned char * V_73 ;
V_73 = F_40 ( V_77 ) ;
V_74 = F_43 ( V_77 ) ;
F_37 ( V_18 , V_34 , V_73 , V_74 ) ;
}
static void
F_44 ( struct V_32 * V_32 ,
struct V_17 * V_18 ,
struct V_76 * V_77 ,
struct V_33 * V_34 ,
int type )
{
int V_6 ;
switch ( type ) {
case V_59 :
F_39 ( V_18 , V_77 , V_34 ) ;
break;
case V_62 :
F_42 ( V_18 , V_77 , V_34 ) ;
break;
default:
F_32 ( 1 ) ;
return;
}
V_6 = F_45 ( V_32 , V_77 ,
& V_18 -> V_41 ) ;
if ( ! V_6 )
V_18 -> V_40 = true ;
}
static int
F_46 ( struct V_32 * V_32 ,
struct V_17 * V_18 ,
bool V_35 ,
struct V_44 * V_45 ,
int type )
{
int V_78 = 0 ;
int V_79 = 0 ;
int V_80 = 0 ;
int V_46 ;
int V_47 , V_48 ;
int V_6 ;
F_15 () ;
V_47 = 0 ;
V_46 = F_14 ( V_32 -> V_49 , V_50 ) ;
V_51:
V_6 = F_16 ( V_45 ) ;
if ( V_6 )
goto V_81;
V_48 = 0 ;
V_79 = V_78 ;
for (; V_47 < F_14 ( V_32 -> V_49 , V_50 ) ; V_47 ++ ) {
struct V_33 * V_34 = F_17 ( V_32 , V_47 ) ;
struct V_76 * V_77 ;
if ( ! V_34 )
continue;
V_78 = 0 ;
F_47 (neigh_entry, rif) {
int V_82 = F_48 ( V_77 ) ;
if ( V_82 != type )
continue;
if ( V_82 == V_62 &&
F_49 ( V_77 ) )
continue;
if ( V_78 < V_79 )
goto V_83;
F_44 ( V_32 , V_18 ,
V_77 , V_34 ,
type ) ;
V_18 -> V_42 = V_80 ;
V_6 = F_18 ( V_45 , V_18 ) ;
if ( V_6 ) {
if ( V_6 == - V_53 ) {
if ( ! V_48 )
goto V_54;
else
goto V_84;
}
goto V_54;
}
V_80 ++ ;
V_48 ++ ;
V_83:
V_78 ++ ;
}
V_79 = 0 ;
}
V_84:
F_19 ( V_45 ) ;
if ( V_47 != V_46 )
goto V_51;
F_20 () ;
return 0 ;
V_81:
V_54:
F_20 () ;
return V_6 ;
}
static int
F_50 ( struct V_32 * V_32 ,
bool V_35 ,
struct V_44 * V_45 ,
int type )
{
struct V_19 V_22 [ V_71 ] ;
struct V_13 V_68 [ V_71 ] ;
struct V_19 V_21 ;
struct V_4 V_5 = { 0 } ;
struct V_17 V_18 = { 0 } ;
int V_6 ;
memset ( V_68 , 0 , V_71 *
sizeof( V_68 [ 0 ] ) ) ;
memset ( V_22 , 0 , V_71 *
sizeof( V_22 [ 0 ] ) ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_35 ( V_68 , & V_5 , type ) ;
V_6 = F_36 ( & V_18 , V_22 ,
V_68 , & V_21 ,
& V_5 , type ) ;
if ( V_6 )
goto V_84;
V_6 = F_46 ( V_32 , & V_18 ,
V_35 , V_45 ,
type ) ;
V_84:
F_21 ( & V_18 ) ;
return V_6 ;
}
static int
F_51 ( void * V_1 , bool V_35 ,
struct V_44 * V_45 )
{
struct V_32 * V_32 = V_1 ;
return F_50 ( V_32 ,
V_35 ,
V_45 , V_59 ) ;
}
static void
F_52 ( struct V_32 * V_32 ,
bool V_55 , int type )
{
int V_47 ;
F_15 () ;
for ( V_47 = 0 ; V_47 < F_14 ( V_32 -> V_49 , V_50 ) ; V_47 ++ ) {
struct V_33 * V_34 = F_17 ( V_32 , V_47 ) ;
struct V_76 * V_77 ;
if ( ! V_34 )
continue;
F_47 (neigh_entry, rif) {
int V_82 = F_48 ( V_77 ) ;
if ( V_82 != type )
continue;
if ( V_82 == V_62 &&
F_49 ( V_77 ) )
continue;
F_53 ( V_32 ,
V_77 ,
V_55 ) ;
}
}
F_20 () ;
}
static int F_54 ( void * V_1 , bool V_55 )
{
struct V_32 * V_32 = V_1 ;
F_52 ( V_32 , V_55 , V_59 ) ;
return 0 ;
}
static T_1
F_55 ( struct V_32 * V_32 , int type )
{
T_1 V_85 = 0 ;
int V_47 ;
F_15 () ;
for ( V_47 = 0 ; V_47 < F_14 ( V_32 -> V_49 , V_50 ) ; V_47 ++ ) {
struct V_33 * V_34 = F_17 ( V_32 , V_47 ) ;
struct V_76 * V_77 ;
if ( ! V_34 )
continue;
F_47 (neigh_entry, rif) {
int V_82 = F_48 ( V_77 ) ;
if ( V_82 != type )
continue;
if ( V_82 == V_62 &&
F_49 ( V_77 ) )
continue;
V_85 ++ ;
}
}
F_20 () ;
return V_85 ;
}
static T_1 F_56 ( void * V_1 )
{
struct V_32 * V_32 = V_1 ;
return F_55 ( V_32 , V_59 ) ;
}
static int F_57 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
return F_28 ( V_56 ,
V_86 ,
& V_87 ,
V_32 , false ) ;
}
static void F_58 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
F_30 ( V_56 ,
V_86 ) ;
}
static int
F_59 ( void * V_1 , struct V_2 * V_3 )
{
return F_31 ( V_3 , V_62 ) ;
}
static int
F_60 ( void * V_1 , bool V_35 ,
struct V_44 * V_45 )
{
struct V_32 * V_32 = V_1 ;
return F_50 ( V_32 ,
V_35 ,
V_45 , V_62 ) ;
}
static int F_61 ( void * V_1 , bool V_55 )
{
struct V_32 * V_32 = V_1 ;
F_52 ( V_32 , V_55 , V_62 ) ;
return 0 ;
}
static T_1 F_62 ( void * V_1 )
{
struct V_32 * V_32 = V_1 ;
return F_55 ( V_32 , V_62 ) ;
}
static int F_63 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
return F_28 ( V_56 ,
V_88 ,
& V_89 ,
V_32 , false ) ;
}
static void F_64 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
F_30 ( V_56 ,
V_88 ) ;
}
int F_65 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
int V_6 ;
V_6 = F_66 ( V_56 ,
& V_90 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_26 ( V_32 ) ;
if ( V_6 )
goto V_91;
V_6 = F_57 ( V_32 ) ;
if ( V_6 )
goto V_92;
V_6 = F_63 ( V_32 ) ;
if ( V_6 )
goto V_93;
return 0 ;
V_93:
F_58 ( V_32 ) ;
V_92:
F_29 ( V_32 ) ;
V_91:
F_67 ( F_27 ( V_32 -> V_49 ) ) ;
return V_6 ;
}
void F_68 ( struct V_32 * V_32 )
{
struct V_56 * V_56 = F_27 ( V_32 -> V_49 ) ;
F_64 ( V_32 ) ;
F_58 ( V_32 ) ;
F_29 ( V_32 ) ;
F_67 ( V_56 ) ;
}
