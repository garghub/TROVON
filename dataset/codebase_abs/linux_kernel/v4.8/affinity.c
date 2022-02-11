static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = 0 ;
}
void F_3 ( void )
{
int V_6 , V_7 , V_8 , V_9 ;
F_2 ( & V_10 . V_11 ) ;
F_4 ( & V_10 . V_11 , V_12 ) ;
V_6 = F_5 ( & V_10 . V_11 ) ;
V_9 = F_5 ( F_6 (
F_7 ( & V_10 . V_11 ) ) ) ;
V_7 = F_7 ( & V_10 . V_11 ) ;
for ( V_8 = 0 ; V_8 < V_6 / V_9 ; V_8 ++ )
V_7 = F_8 ( V_7 , & V_10 . V_11 ) ;
for (; V_8 < V_6 ; V_8 ++ ) {
F_9 ( V_7 , & V_10 . V_11 ) ;
V_7 = F_8 ( V_7 , & V_10 . V_11 ) ;
}
}
int F_10 ( void )
{
int V_13 ;
struct V_14 * V_15 = NULL ;
const struct V_16 * V_17 = V_18 ;
F_2 ( & V_10 . V_19 . V_4 ) ;
F_4 ( & V_10 . V_19 . V_3 , V_12 ) ;
V_10 . V_19 . V_5 = 0 ;
V_10 . V_20 =
F_5 ( F_6 (
F_7 ( & V_10 . V_19 . V_3 )
) ) ;
V_10 . V_21 = V_21 () ;
V_10 . V_22 = V_22 () ;
F_3 () ;
V_23 = F_11 ( F_12 () ,
sizeof( * V_23 ) , V_24 ) ;
if ( ! V_23 )
return - V_25 ;
while ( V_17 -> V_26 ) {
V_15 = NULL ;
while ( ( V_15 = F_13 ( V_17 -> V_26 , V_17 -> V_27 , V_15 ) ) ) {
V_13 = F_14 ( V_15 -> V_28 ) ;
if ( V_13 < 0 )
V_13 = F_15 () ;
V_23 [ V_13 ] ++ ;
}
V_17 ++ ;
}
return 0 ;
}
void F_16 ( void )
{
struct V_29 * V_30 , * V_31 ;
struct V_32 * V_33 ;
F_17 ( & V_10 . V_34 ) ;
F_18 (pos, q, &node_affinity.list) {
V_33 = F_19 ( V_30 , struct V_32 ,
V_35 ) ;
F_20 ( V_30 ) ;
F_21 ( V_33 ) ;
}
F_22 ( & V_10 . V_34 ) ;
F_21 ( V_23 ) ;
}
static struct V_32 * F_23 ( int V_13 )
{
struct V_32 * V_33 ;
V_33 = F_24 ( sizeof( * V_33 ) , V_24 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_13 = V_13 ;
F_25 ( & V_33 -> V_35 ) ;
return V_33 ;
}
static void F_26 ( struct V_32 * V_33 )
{
F_27 ( & V_33 -> V_35 , & V_10 . V_35 ) ;
}
static struct V_32 * F_28 ( int V_13 )
{
struct V_29 * V_30 ;
struct V_32 * V_33 ;
F_29 (pos, &node_affinity.list) {
V_33 = F_19 ( V_30 , struct V_32 , V_35 ) ;
if ( V_33 -> V_13 == V_13 )
return V_33 ;
}
return NULL ;
}
int F_30 ( struct V_36 * V_37 )
{
int V_13 = F_14 ( V_37 -> V_38 -> V_28 ) ;
struct V_32 * V_33 ;
const struct V_39 * V_40 ;
int V_7 , V_6 , V_8 ;
if ( V_13 < 0 )
V_13 = F_15 () ;
V_37 -> V_13 = V_13 ;
V_40 = F_31 ( V_37 -> V_13 ) ;
if ( F_7 ( V_40 ) >= V_41 )
V_40 = F_32 ( 0 ) ;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
F_22 ( & V_10 . V_34 ) ;
if ( ! V_33 ) {
V_33 = F_23 ( V_13 ) ;
if ( ! V_33 ) {
F_33 ( V_37 ,
L_1 ) ;
return - V_25 ;
}
F_1 ( & V_33 -> V_42 ) ;
F_1 ( & V_33 -> V_43 ) ;
F_2 ( & V_33 -> V_44 ) ;
F_34 ( & V_33 -> V_42 . V_3 , & V_10 . V_11 ,
V_40 ) ;
V_6 = F_5 ( & V_33 -> V_42 . V_3 ) ;
V_7 = F_7 ( & V_33 -> V_42 . V_3 ) ;
if ( V_6 == 1 ) {
F_35 ( V_7 , & V_33 -> V_43 . V_3 ) ;
F_35 ( V_7 , & V_33 -> V_44 ) ;
} else {
F_9 ( V_7 , & V_33 -> V_42 . V_3 ) ;
F_35 ( V_7 , & V_33 -> V_44 ) ;
V_7 = F_8 ( V_7 ,
& V_33 -> V_42 . V_3 ) ;
for ( V_8 = 0 ;
V_8 < ( V_37 -> V_45 - 1 ) *
V_23 [ V_37 -> V_13 ] ;
V_8 ++ ) {
F_9 ( V_7 ,
& V_33 -> V_42 . V_3 ) ;
F_35 ( V_7 ,
& V_33 -> V_43 . V_3 ) ;
V_7 = F_8 ( V_7 ,
& V_33 -> V_42 . V_3 ) ;
if ( V_7 >= V_41 )
break;
}
if ( F_5 ( & V_33 -> V_42 . V_3 ) == 0 )
F_4 ( & V_33 -> V_42 . V_3 ,
& V_33 -> V_44 ) ;
}
F_17 ( & V_10 . V_34 ) ;
F_26 ( V_33 ) ;
F_22 ( & V_10 . V_34 ) ;
}
return 0 ;
}
int F_36 ( struct V_36 * V_37 , struct V_46 * V_47 )
{
int V_48 ;
T_1 V_49 ;
struct V_32 * V_33 ;
struct V_1 * V_2 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_52 * V_53 = NULL ;
char V_54 [ 64 ] ;
int V_55 = - 1 ;
V_54 [ 0 ] = '\0' ;
F_2 ( & V_47 -> V_3 ) ;
V_48 = F_37 ( & V_49 , V_24 ) ;
if ( ! V_48 )
return - V_25 ;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
F_22 ( & V_10 . V_34 ) ;
switch ( V_47 -> type ) {
case V_56 :
V_51 = (struct V_50 * ) V_47 -> V_57 ;
F_38 ( V_54 , 64 , L_2 , V_51 -> V_58 ) ;
V_2 = & V_33 -> V_42 ;
break;
case V_59 :
V_55 = F_7 ( & V_33 -> V_44 ) ;
break;
case V_60 :
V_53 = (struct V_52 * ) V_47 -> V_57 ;
if ( V_53 -> V_61 == V_62 )
V_55 = F_7 ( & V_33 -> V_44 ) ;
else
V_2 = & V_33 -> V_43 ;
F_38 ( V_54 , 64 , L_3 , V_53 -> V_61 ) ;
break;
default:
F_33 ( V_37 , L_4 , V_47 -> type ) ;
return - V_63 ;
}
if ( V_55 == - 1 && V_2 ) {
F_17 ( & V_10 . V_34 ) ;
if ( F_39 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
F_40 ( V_49 , & V_2 -> V_3 , & V_2 -> V_4 ) ;
V_55 = F_7 ( V_49 ) ;
F_35 ( V_55 , & V_2 -> V_4 ) ;
F_22 ( & V_10 . V_34 ) ;
}
switch ( V_47 -> type ) {
case V_56 :
V_51 -> V_55 = V_55 ;
break;
case V_59 :
case V_60 :
case V_64 :
break;
}
F_35 ( V_55 , & V_47 -> V_3 ) ;
F_41 ( V_37 , L_5 ,
V_47 -> V_47 . V_65 , V_66 [ V_47 -> type ] ,
V_54 , V_55 ) ;
F_42 ( V_47 -> V_47 . V_65 , & V_47 -> V_3 ) ;
F_43 ( V_49 ) ;
return 0 ;
}
void F_44 ( struct V_36 * V_37 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = NULL ;
struct V_52 * V_53 ;
struct V_32 * V_33 ;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
F_22 ( & V_10 . V_34 ) ;
switch ( V_47 -> type ) {
case V_56 :
V_2 = & V_33 -> V_42 ;
break;
case V_59 :
break;
case V_60 :
V_53 = (struct V_52 * ) V_47 -> V_57 ;
if ( V_53 -> V_61 != V_62 )
V_2 = & V_33 -> V_43 ;
break;
default:
return;
}
if ( V_2 ) {
F_17 ( & V_10 . V_34 ) ;
F_40 ( & V_2 -> V_4 , & V_2 -> V_4 , & V_47 -> V_3 ) ;
if ( F_45 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_4 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
F_22 ( & V_10 . V_34 ) ;
}
F_42 ( V_47 -> V_47 . V_65 , NULL ) ;
F_2 ( & V_47 -> V_3 ) ;
}
static void F_46 ( T_2 V_67 , T_1 V_68 ,
struct V_69 * V_70 )
{
int V_6 , V_7 , V_8 ;
T_2 V_71 = V_10 . V_22 /
V_70 -> V_20 /
V_10 . V_21 ;
F_4 ( V_68 , & V_70 -> V_19 . V_3 ) ;
if ( V_70 -> V_20 > 0 ) {
V_6 = F_5 ( V_68 ) ;
V_7 = F_7 ( V_68 ) ;
for ( V_8 = 0 ;
V_8 < V_71 * V_10 . V_21 ;
V_8 ++ )
V_7 = F_8 ( V_7 , V_68 ) ;
for (; V_8 < V_6 ; V_8 ++ ) {
F_9 ( V_7 , V_68 ) ;
V_7 = F_8 ( V_7 , V_68 ) ;
}
F_47 ( V_68 , V_68 ,
V_71 *
V_10 . V_21 *
V_67 ) ;
}
}
int F_48 ( int V_13 )
{
int V_55 = - 1 , V_48 , V_8 ;
struct V_32 * V_33 ;
T_1 V_49 , V_68 , V_72 , V_73 ;
const struct V_39 * V_74 ,
* V_75 = F_49 ( V_76 ) ;
struct V_69 * V_70 = & V_10 ;
struct V_1 * V_2 = & V_70 -> V_19 ;
if ( F_5 ( V_75 ) == 1 ) {
F_50 ( V_77 , L_6 ,
V_76 -> V_78 , V_76 -> V_79 ,
F_51 ( V_75 ) ) ;
V_55 = F_7 ( V_75 ) ;
F_35 ( V_55 , & V_2 -> V_4 ) ;
goto V_80;
} else if ( F_5 ( V_75 ) < F_5 ( & V_2 -> V_3 ) ) {
F_50 ( V_77 , L_7 ,
V_76 -> V_78 , V_76 -> V_79 ,
F_51 ( V_75 ) ) ;
goto V_80;
}
V_48 = F_37 ( & V_49 , V_24 ) ;
if ( ! V_48 )
goto V_80;
V_48 = F_37 ( & V_68 , V_24 ) ;
if ( ! V_48 )
goto V_81;
V_48 = F_37 ( & V_72 , V_24 ) ;
if ( ! V_48 )
goto V_82;
V_48 = F_37 ( & V_73 , V_24 ) ;
if ( ! V_48 )
goto V_83;
F_17 ( & V_70 -> V_34 ) ;
if ( F_39 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
V_33 = F_28 ( V_13 ) ;
if ( V_33 ) {
F_4 ( V_73 , ( V_33 -> V_42 . V_5 ?
& V_33 -> V_42 . V_3 :
& V_33 -> V_42 . V_4 ) ) ;
F_52 ( V_73 , V_73 , ( V_33 -> V_43 . V_5 ?
& V_33 -> V_43 . V_3 :
& V_33 -> V_43 . V_4 ) ) ;
F_52 ( V_73 , V_73 , & V_33 -> V_44 ) ;
}
F_50 ( V_77 , L_8 ,
F_51 ( V_73 ) ) ;
F_4 ( V_68 , & V_2 -> V_3 ) ;
if ( V_70 -> V_20 > 0 ) {
for ( V_8 = 0 ; V_8 < V_70 -> V_20 ; V_8 ++ ) {
F_46 ( V_8 , V_68 , V_70 ) ;
F_40 ( V_49 , V_68 , & V_2 -> V_4 ) ;
if ( ! F_45 ( V_49 ) )
break;
}
}
F_50 ( V_77 , L_9 ,
F_51 ( V_68 ) ) ;
V_74 = F_31 ( V_13 ) ;
F_50 ( V_77 , L_10 , V_13 ,
F_51 ( V_74 ) ) ;
F_34 ( V_72 , V_68 , V_74 ) ;
F_40 ( V_72 , V_72 , & V_2 -> V_4 ) ;
F_50 ( V_77 , L_11 , V_13 ,
F_51 ( V_72 ) ) ;
F_40 ( V_49 , V_72 , V_73 ) ;
if ( ! F_45 ( V_49 ) )
F_4 ( V_72 , V_49 ) ;
if ( F_45 ( V_72 ) ) {
F_40 ( V_72 , V_68 , & V_2 -> V_4 ) ;
F_40 ( V_72 , V_72 , V_74 ) ;
F_50 ( V_77 ,
L_12 ,
F_51 ( V_72 ) ) ;
F_40 ( V_49 , V_72 , V_73 ) ;
if ( ! F_45 ( V_49 ) )
F_4 ( V_72 , V_49 ) ;
}
F_50 ( V_77 , L_13 ,
F_51 ( V_72 ) ) ;
V_55 = F_7 ( V_72 ) ;
if ( V_55 >= V_41 )
V_55 = - 1 ;
else
F_35 ( V_55 , & V_2 -> V_4 ) ;
F_22 ( & V_70 -> V_34 ) ;
F_50 ( V_77 , L_14 , V_55 ) ;
F_43 ( V_73 ) ;
V_83:
F_43 ( V_72 ) ;
V_82:
F_43 ( V_68 ) ;
V_81:
F_43 ( V_49 ) ;
V_80:
return V_55 ;
}
void F_53 ( int V_55 )
{
struct V_69 * V_70 = & V_10 ;
struct V_1 * V_2 = & V_70 -> V_19 ;
if ( V_55 < 0 )
return;
F_17 ( & V_70 -> V_34 ) ;
F_9 ( V_55 , & V_2 -> V_4 ) ;
F_50 ( V_77 , L_15 , V_55 ) ;
if ( F_45 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_4 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
F_22 ( & V_70 -> V_34 ) ;
}
int F_54 ( struct V_36 * V_37 , const char * V_84 ,
T_3 V_85 )
{
struct V_32 * V_33 ;
T_1 V_3 ;
int V_48 , V_8 ;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
F_22 ( & V_10 . V_34 ) ;
if ( ! V_33 )
return - V_63 ;
V_48 = F_37 ( & V_3 , V_24 ) ;
if ( ! V_48 )
return - V_25 ;
V_48 = F_55 ( V_84 , V_3 ) ;
if ( V_48 )
goto V_86;
if ( ! F_56 ( V_3 , V_12 ) || F_45 ( V_3 ) ) {
F_57 ( V_37 , L_16 ) ;
V_48 = - V_63 ;
goto V_86;
}
F_58 ( & V_87 ) ;
F_1 ( & V_33 -> V_42 ) ;
F_4 ( & V_33 -> V_42 . V_3 , V_3 ) ;
for ( V_8 = 0 ; V_8 < V_37 -> V_88 ; V_8 ++ ) {
struct V_46 * V_47 ;
V_47 = & V_37 -> V_89 [ V_8 ] ;
if ( V_47 -> type != V_56 )
continue;
V_48 = F_36 ( V_37 , V_47 ) ;
if ( V_48 )
break;
}
F_59 ( & V_87 ) ;
V_86:
F_43 ( V_3 ) ;
return V_48 ? V_48 : F_60 ( V_84 , V_90 ) ;
}
int F_61 ( struct V_36 * V_37 , char * V_84 )
{
struct V_32 * V_33 ;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
F_22 ( & V_10 . V_34 ) ;
if ( ! V_33 )
return - V_63 ;
F_58 ( & V_87 ) ;
F_62 ( true , V_84 , & V_33 -> V_42 . V_3 ) ;
F_59 ( & V_87 ) ;
return F_60 ( V_84 , V_90 ) ;
}
