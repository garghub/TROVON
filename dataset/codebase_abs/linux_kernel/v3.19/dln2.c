int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
struct V_9 * V_10 , * V_11 ;
unsigned long V_12 ;
int V_13 = 0 ;
V_11 = F_3 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_16 = V_4 ;
V_11 -> V_2 = V_2 ;
F_4 ( & V_6 -> V_17 , V_12 ) ;
F_5 (i, &dln2->event_cb_list, list) {
if ( V_10 -> V_3 == V_3 ) {
V_13 = - V_18 ;
break;
}
}
if ( ! V_13 )
F_6 ( & V_11 -> V_19 , & V_6 -> V_20 ) ;
F_7 ( & V_6 -> V_17 , V_12 ) ;
if ( V_13 )
F_8 ( V_11 ) ;
return V_13 ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
struct V_9 * V_10 ;
unsigned long V_12 ;
bool V_21 = false ;
F_4 ( & V_6 -> V_17 , V_12 ) ;
F_5 (i, &dln2->event_cb_list, list) {
if ( V_10 -> V_3 == V_3 ) {
F_10 ( & V_10 -> V_19 ) ;
V_21 = true ;
break;
}
}
F_7 ( & V_6 -> V_17 , V_12 ) ;
if ( V_21 ) {
F_11 () ;
F_8 ( V_10 ) ;
}
}
static bool F_12 ( struct V_5 * V_6 , struct V_22 * V_22 ,
T_1 V_23 , T_1 V_24 )
{
struct V_25 * V_7 = & V_6 -> V_26 -> V_7 ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_23 ] ;
struct V_30 * V_31 ;
bool V_32 = false ;
if ( V_24 >= V_33 )
goto V_34;
V_31 = & V_28 -> V_35 [ V_24 ] ;
F_13 ( & V_28 -> V_36 ) ;
if ( V_31 -> V_37 && ! V_31 -> V_22 ) {
V_31 -> V_22 = V_22 ;
F_14 ( & V_31 -> V_38 ) ;
V_32 = true ;
}
F_15 ( & V_28 -> V_36 ) ;
V_34:
if ( ! V_32 )
F_16 ( V_7 , L_1 , V_23 , V_24 ) ;
return V_32 ;
}
static void F_17 ( struct V_5 * V_6 , T_1 V_3 , T_1 V_39 ,
void * V_40 , int V_41 )
{
struct V_9 * V_10 ;
F_18 () ;
F_19 (i, &dln2->event_cb_list, list) {
if ( V_10 -> V_3 == V_3 ) {
V_10 -> V_16 ( V_10 -> V_2 , V_39 , V_40 , V_41 ) ;
break;
}
}
F_20 () ;
}
static void F_21 ( struct V_22 * V_22 )
{
struct V_5 * V_6 = V_22 -> V_42 ;
struct V_43 * V_44 = V_22 -> V_45 ;
struct V_25 * V_7 = & V_6 -> V_26 -> V_7 ;
T_1 V_3 , V_39 , V_23 , V_46 ;
T_3 * V_40 ;
int V_41 ;
int V_47 ;
switch ( V_22 -> V_48 ) {
case 0 :
break;
case - V_49 :
case - V_50 :
case - V_51 :
case - V_52 :
F_22 ( V_7 , L_2 , V_22 -> V_48 ) ;
return;
default:
F_22 ( V_7 , L_3 , V_22 -> V_48 ) ;
goto V_34;
}
if ( V_22 -> V_53 < sizeof( struct V_43 ) ) {
F_23 ( V_7 , L_4 , V_22 -> V_53 ) ;
goto V_34;
}
V_23 = F_24 ( V_44 -> V_23 ) ;
V_3 = F_24 ( V_44 -> V_3 ) ;
V_39 = F_24 ( V_44 -> V_39 ) ;
V_46 = F_24 ( V_44 -> V_46 ) ;
if ( V_46 != V_22 -> V_53 ) {
F_23 ( V_7 , L_5 ,
V_23 , V_3 , V_39 , V_46 , V_22 -> V_53 ) ;
goto V_34;
}
if ( V_23 >= V_54 ) {
F_16 ( V_7 , L_6 , V_23 ) ;
goto V_34;
}
V_40 = V_22 -> V_45 + sizeof( struct V_43 ) ;
V_41 = V_22 -> V_53 - sizeof( struct V_43 ) ;
if ( V_23 == V_55 ) {
F_17 ( V_6 , V_3 , V_39 , V_40 , V_41 ) ;
} else {
if ( F_12 ( V_6 , V_22 , V_23 , V_39 ) )
return;
}
V_34:
V_47 = F_25 ( V_22 , V_56 ) ;
if ( V_47 < 0 )
F_23 ( V_7 , L_7 , V_47 ) ;
}
static void * F_26 ( T_1 V_23 , T_1 V_57 , T_1 V_39 , const void * V_58 ,
int * V_59 , T_4 V_60 )
{
int V_41 ;
void * V_61 ;
struct V_43 * V_44 ;
V_41 = * V_59 + sizeof( * V_44 ) ;
V_61 = F_27 ( V_41 , V_60 ) ;
if ( ! V_61 )
return NULL ;
V_44 = (struct V_43 * ) V_61 ;
V_44 -> V_3 = F_28 ( V_57 ) ;
V_44 -> V_46 = F_28 ( V_41 ) ;
V_44 -> V_39 = F_28 ( V_39 ) ;
V_44 -> V_23 = F_28 ( V_23 ) ;
memcpy ( V_61 + sizeof( * V_44 ) , V_58 , * V_59 ) ;
* V_59 = V_41 ;
return V_61 ;
}
static int F_29 ( struct V_5 * V_6 , T_1 V_23 , T_1 V_57 , T_1 V_39 ,
const void * V_58 , int V_59 )
{
int V_13 = 0 ;
int V_41 = V_59 ;
void * V_61 ;
int V_62 ;
V_61 = F_26 ( V_23 , V_57 , V_39 , V_58 , & V_41 , V_14 ) ;
if ( ! V_61 )
return - V_15 ;
V_13 = F_30 ( V_6 -> V_63 ,
F_31 ( V_6 -> V_63 , V_6 -> V_64 ) ,
V_61 , V_41 , & V_62 , V_65 ) ;
F_8 ( V_61 ) ;
return V_13 ;
}
static bool F_32 ( struct V_5 * V_6 , T_1 V_23 , int * V_66 )
{
struct V_27 * V_28 ;
unsigned long V_12 ;
if ( V_6 -> V_67 ) {
* V_66 = - V_68 ;
return true ;
}
V_28 = & V_6 -> V_29 [ V_23 ] ;
F_4 ( & V_28 -> V_36 , V_12 ) ;
* V_66 = F_33 ( V_28 -> V_69 , V_33 ) ;
if ( * V_66 < V_33 ) {
struct V_30 * V_31 = & V_28 -> V_35 [ * V_66 ] ;
F_34 ( * V_66 , V_28 -> V_69 ) ;
V_31 -> V_37 = true ;
}
F_7 ( & V_28 -> V_36 , V_12 ) ;
return * V_66 < V_33 ;
}
static int F_35 ( struct V_5 * V_6 , T_1 V_23 )
{
int V_13 ;
int V_66 ;
V_13 = F_36 ( V_6 -> V_29 [ V_23 ] . V_70 ,
F_32 ( V_6 , V_23 , & V_66 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return V_66 ;
}
static void F_37 ( struct V_5 * V_6 , T_1 V_23 , int V_66 )
{
struct V_27 * V_28 ;
struct V_22 * V_22 = NULL ;
unsigned long V_12 ;
struct V_30 * V_31 ;
V_28 = & V_6 -> V_29 [ V_23 ] ;
F_4 ( & V_28 -> V_36 , V_12 ) ;
F_38 ( V_66 , V_28 -> V_69 ) ;
V_31 = & V_28 -> V_35 [ V_66 ] ;
V_31 -> V_37 = false ;
V_22 = V_31 -> V_22 ;
V_31 -> V_22 = NULL ;
F_39 ( & V_31 -> V_38 ) ;
F_7 ( & V_28 -> V_36 , V_12 ) ;
if ( V_22 ) {
int V_47 ;
struct V_25 * V_7 = & V_6 -> V_26 -> V_7 ;
V_47 = F_25 ( V_22 , V_14 ) ;
if ( V_47 < 0 )
F_23 ( V_7 , L_7 , V_47 ) ;
}
F_40 ( & V_28 -> V_70 ) ;
}
static int F_41 ( struct V_5 * V_6 , T_1 V_23 , T_1 V_57 ,
const void * V_58 , unsigned V_59 ,
void * V_71 , unsigned * V_72 )
{
int V_13 = 0 ;
int V_24 ;
struct V_73 * V_74 ;
struct V_30 * V_31 ;
struct V_25 * V_7 = & V_6 -> V_26 -> V_7 ;
const unsigned long V_75 = V_65 * V_76 / 1000 ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_23 ] ;
int V_46 ;
F_13 ( & V_6 -> V_77 ) ;
if ( ! V_6 -> V_67 )
V_6 -> V_78 ++ ;
else
V_13 = - V_68 ;
F_15 ( & V_6 -> V_77 ) ;
if ( V_13 )
return V_13 ;
V_24 = F_35 ( V_6 , V_23 ) ;
if ( V_24 < 0 ) {
V_13 = V_24 ;
goto V_79;
}
V_13 = F_29 ( V_6 , V_23 , V_57 , V_24 , V_58 , V_59 ) ;
if ( V_13 < 0 ) {
F_23 ( V_7 , L_8 , V_13 ) ;
goto V_80;
}
V_31 = & V_28 -> V_35 [ V_24 ] ;
V_13 = F_42 ( & V_31 -> V_38 , V_75 ) ;
if ( V_13 <= 0 ) {
if ( ! V_13 )
V_13 = - V_81 ;
goto V_80;
} else {
V_13 = 0 ;
}
if ( V_6 -> V_67 ) {
V_13 = - V_68 ;
goto V_80;
}
V_74 = V_31 -> V_22 -> V_45 ;
V_46 = F_24 ( V_74 -> V_44 . V_46 ) ;
if ( V_46 < sizeof( * V_74 ) ) {
V_13 = - V_82 ;
goto V_80;
}
if ( F_24 ( V_74 -> V_83 ) > 0x80 ) {
F_22 ( V_7 , L_9 ,
V_23 , F_24 ( V_74 -> V_83 ) ) ;
V_13 = - V_84 ;
goto V_80;
}
if ( ! V_71 )
goto V_80;
if ( * V_72 > V_46 - sizeof( * V_74 ) )
* V_72 = V_46 - sizeof( * V_74 ) ;
memcpy ( V_71 , V_74 + 1 , * V_72 ) ;
V_80:
F_37 ( V_6 , V_23 , V_24 ) ;
V_79:
F_13 ( & V_6 -> V_77 ) ;
V_6 -> V_78 -- ;
F_15 ( & V_6 -> V_77 ) ;
if ( V_6 -> V_67 )
F_43 ( & V_6 -> V_85 ) ;
return V_13 ;
}
int F_44 ( struct V_1 * V_2 , T_1 V_57 ,
const void * V_58 , unsigned V_59 ,
void * V_71 , unsigned * V_72 )
{
struct V_86 * V_87 ;
struct V_5 * V_6 ;
T_1 V_23 ;
V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
V_87 = F_45 ( & V_2 -> V_7 ) ;
V_23 = V_87 -> V_23 ;
return F_41 ( V_6 , V_23 , V_57 , V_58 , V_59 , V_71 ,
V_72 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
int V_13 ;
T_5 V_88 ;
int V_41 = sizeof( V_88 ) ;
V_13 = F_41 ( V_6 , V_89 , V_90 ,
NULL , 0 , & V_88 , & V_41 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_41 < sizeof( V_88 ) )
return - V_84 ;
if ( F_47 ( V_88 ) != V_91 ) {
F_23 ( & V_6 -> V_26 -> V_7 , L_10 ,
F_47 ( V_88 ) ) ;
return - V_68 ;
}
return 0 ;
}
static int F_48 ( struct V_5 * V_6 )
{
int V_13 ;
T_5 V_92 ;
int V_41 = sizeof( V_92 ) ;
struct V_25 * V_7 = & V_6 -> V_26 -> V_7 ;
V_13 = F_41 ( V_6 , V_89 , V_93 , NULL , 0 ,
& V_92 , & V_41 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_41 < sizeof( V_92 ) )
return - V_84 ;
F_49 ( V_7 , L_11 , F_47 ( V_92 ) ) ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_46 ( V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_48 ( V_6 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_94 ; V_10 ++ ) {
F_52 ( V_6 -> V_95 [ V_10 ] ) ;
F_53 ( V_6 -> V_95 [ V_10 ] ) ;
F_8 ( V_6 -> V_96 [ V_10 ] ) ;
}
}
static void F_54 ( struct V_5 * V_6 )
{
F_51 ( V_6 ) ;
F_55 ( V_6 -> V_63 ) ;
F_8 ( V_6 ) ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_97 * V_98 )
{
int V_10 ;
int V_13 ;
const int V_99 = V_100 ;
struct V_25 * V_7 = & V_6 -> V_26 -> V_7 ;
for ( V_10 = 0 ; V_10 < V_94 ; V_10 ++ ) {
V_6 -> V_96 [ V_10 ] = F_27 ( V_99 , V_14 ) ;
if ( ! V_6 -> V_96 [ V_10 ] )
return - V_15 ;
V_6 -> V_95 [ V_10 ] = F_57 ( 0 , V_14 ) ;
if ( ! V_6 -> V_95 [ V_10 ] )
return - V_15 ;
F_58 ( V_6 -> V_95 [ V_10 ] , V_6 -> V_63 ,
F_59 ( V_6 -> V_63 , V_6 -> V_101 ) ,
V_6 -> V_96 [ V_10 ] , V_99 , F_21 , V_6 ) ;
V_13 = F_25 ( V_6 -> V_95 [ V_10 ] , V_14 ) ;
if ( V_13 < 0 ) {
F_23 ( V_7 , L_12 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static void F_60 ( struct V_102 * V_26 )
{
struct V_5 * V_6 = F_61 ( V_26 ) ;
int V_10 , V_103 ;
F_13 ( & V_6 -> V_77 ) ;
V_6 -> V_67 = true ;
F_15 ( & V_6 -> V_77 ) ;
for ( V_10 = 0 ; V_10 < V_54 ; V_10 ++ ) {
struct V_27 * V_28 = & V_6 -> V_29 [ V_10 ] ;
unsigned long V_12 ;
F_4 ( & V_28 -> V_36 , V_12 ) ;
for ( V_103 = 0 ; V_103 < V_33 ; V_103 ++ ) {
struct V_30 * V_31 = & V_28 -> V_35 [ V_103 ] ;
if ( V_31 -> V_37 )
F_14 ( & V_31 -> V_38 ) ;
}
F_7 ( & V_28 -> V_36 , V_12 ) ;
}
F_62 ( V_6 -> V_85 , ! V_6 -> V_78 ) ;
F_63 ( & V_26 -> V_7 ) ;
F_54 ( V_6 ) ;
}
static int F_64 ( struct V_102 * V_26 ,
const struct V_104 * V_105 )
{
struct V_97 * V_98 = V_26 -> V_106 ;
struct V_25 * V_7 = & V_26 -> V_7 ;
struct V_5 * V_6 ;
int V_13 ;
int V_10 , V_103 ;
if ( V_98 -> V_107 . V_108 != 0 ||
V_98 -> V_107 . V_109 < 2 )
return - V_68 ;
V_6 = F_3 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 )
return - V_15 ;
V_6 -> V_64 = V_98 -> V_110 [ 0 ] . V_107 . V_111 ;
V_6 -> V_101 = V_98 -> V_110 [ 1 ] . V_107 . V_111 ;
V_6 -> V_63 = F_65 ( F_66 ( V_26 ) ) ;
V_6 -> V_26 = V_26 ;
F_67 ( V_26 , V_6 ) ;
F_68 ( & V_6 -> V_85 ) ;
for ( V_10 = 0 ; V_10 < V_54 ; V_10 ++ ) {
F_68 ( & V_6 -> V_29 [ V_10 ] . V_70 ) ;
F_69 ( & V_6 -> V_29 [ V_10 ] . V_36 ) ;
for ( V_103 = 0 ; V_103 < V_33 ; V_103 ++ )
F_70 ( & V_6 -> V_29 [ V_10 ] . V_35 [ V_103 ] . V_38 ) ;
}
F_69 ( & V_6 -> V_17 ) ;
F_69 ( & V_6 -> V_77 ) ;
F_71 ( & V_6 -> V_20 ) ;
V_13 = F_56 ( V_6 , V_98 ) ;
if ( V_13 )
goto V_112;
V_13 = F_50 ( V_6 ) ;
if ( V_13 < 0 ) {
F_23 ( V_7 , L_13 ) ;
goto V_112;
}
V_13 = F_72 ( V_7 , V_113 , F_73 ( V_113 ) ) ;
if ( V_13 != 0 ) {
F_23 ( V_7 , L_14 ) ;
goto V_112;
}
return 0 ;
V_112:
F_54 ( V_6 ) ;
return V_13 ;
}
