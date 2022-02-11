static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_6 ) ;
return V_5 -> V_7 ? V_8 : V_9 ;
}
static void F_3 ( struct V_4 * V_5 )
{
int V_10 ;
F_4 () ;
if ( V_5 -> V_7 != V_5 -> V_11 && V_5 -> V_12 &&
F_5 ( & V_5 -> V_13 , 1 , 1 ) ) {
V_5 -> V_14 [ 4 ] = V_5 -> V_11 = V_5 -> V_7 ;
V_10 = F_6 ( V_5 -> V_15 , V_16 ) ;
if ( V_10 ) {
F_7 ( V_5 -> V_17 , L_1 ,
V_10 ) ;
F_8 ( & V_5 -> V_13 ) ;
}
}
}
static void F_9 ( struct V_2 * V_3 , enum
V_1 V_18 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 , V_6 ) ;
V_5 -> V_7 = V_18 != V_9 ;
F_3 ( V_5 ) ;
}
static void F_10 ( struct V_19 * V_19 )
{
struct V_4 * V_5 = V_19 -> V_20 ;
F_8 ( & V_5 -> V_13 ) ;
switch ( V_19 -> V_21 ) {
case 0 :
break;
case - V_22 :
case - V_23 :
case - V_24 :
F_11 ( V_19 ) ;
return;
case - V_25 :
default:
F_12 ( V_5 -> V_17 , L_2 , V_19 -> V_21 ) ;
break;
}
F_3 ( V_5 ) ;
}
static void F_13 ( struct V_4 * V_5 , T_1 * V_26 )
{
struct V_27 V_28 ;
unsigned V_29 , V_30 , V_31 ;
bool V_32 = false ;
F_14 ( & V_28 ) ;
for ( V_29 = 0 ; V_29 < 128 ; V_29 ++ ) {
V_30 = V_26 [ V_29 ] & 0xfe ;
switch ( V_30 ) {
case 0xfe :
V_28 . V_33 = false ;
V_28 . V_34 = V_35 ;
if ( F_15 ( V_5 -> V_36 , & V_28 ) )
V_32 = true ;
break;
case 0 :
V_28 . V_33 = true ;
V_28 . V_34 = V_35 ;
if ( F_15 ( V_5 -> V_36 , & V_28 ) )
V_32 = true ;
break;
default:
if ( V_30 & 2 ) {
V_31 = F_16 ( V_30 | 1 ) ;
V_28 . V_33 = true ;
} else {
V_31 = F_17 ( V_30 ) - 1 ;
V_28 . V_33 = false ;
}
V_28 . V_34 = V_37 * ( 8 - V_31 ) ;
if ( F_15 ( V_5 -> V_36 , & V_28 ) )
V_32 = true ;
V_28 . V_33 = ! V_28 . V_33 ;
V_28 . V_34 = V_37 * V_31 ;
if ( F_15 ( V_5 -> V_36 , & V_28 ) )
V_32 = true ;
break;
}
}
if ( V_32 )
F_18 ( V_5 -> V_36 ) ;
}
static void F_19 ( struct V_19 * V_19 )
{
struct V_4 * V_5 = V_19 -> V_20 ;
int V_36 ;
switch ( V_19 -> V_21 ) {
case 0 :
F_13 ( V_5 , V_19 -> V_38 ) ;
break;
case - V_22 :
case - V_23 :
case - V_24 :
F_11 ( V_19 ) ;
return;
case - V_25 :
default:
F_12 ( V_5 -> V_17 , L_2 , V_19 -> V_21 ) ;
break;
}
V_36 = F_6 ( V_19 , V_16 ) ;
if ( V_36 && V_36 != - V_39 )
F_7 ( V_5 -> V_17 , L_3 , V_36 ) ;
}
static int F_20 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_4 * V_5 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_36 ;
int V_29 , V_49 , V_10 ;
int V_50 = - 1 ;
V_5 = F_21 ( sizeof( * V_5 ) , V_51 ) ;
V_36 = F_22 () ;
if ( ! V_5 || ! V_36 ) {
V_10 = - V_52 ;
goto V_53;
}
for ( V_29 = 0 ; V_29 < V_41 -> V_54 && V_50 == - 1 ; V_29 ++ ) {
int V_55 , V_56 = - 1 , V_57 = - 1 ;
V_45 = & V_41 -> V_50 [ V_29 ] . V_47 ;
for ( V_49 = 0 ; V_49 < V_45 -> V_58 ; V_49 ++ ) {
V_47 = & V_41 -> V_50 [ V_29 ] . V_59 [ V_49 ] . V_47 ;
V_55 = F_23 ( V_47 -> V_60 ) ;
if ( F_24 ( V_47 ) &&
F_25 ( V_47 ) &&
V_55 == 0x10 )
V_57 = V_49 ;
else if ( F_26 ( V_47 ) &&
F_27 ( V_47 ) &&
V_55 == 0x20 )
V_56 = V_49 ;
if ( V_56 != - 1 && V_57 != - 1 ) {
V_5 -> V_56 = V_56 ;
V_5 -> V_57 = V_57 ;
V_50 = V_29 ;
break;
}
}
}
if ( V_50 == - 1 ) {
F_28 ( & V_41 -> V_17 , L_4 ) ;
V_10 = - V_39 ;
goto V_53;
}
V_5 -> V_17 = & V_41 -> V_17 ;
V_5 -> V_12 = F_29 ( V_41 ) ;
V_5 -> V_36 = V_36 ;
V_10 = F_30 ( V_5 -> V_12 , 0 , V_50 ) ;
if ( V_10 )
goto V_53;
for ( V_29 = 0 ; V_29 < V_61 ; V_29 ++ ) {
struct V_19 * V_19 = F_31 ( 8 , V_51 ) ;
void * V_62 ;
if ( ! V_19 ) {
V_10 = - V_52 ;
goto V_53;
}
V_19 -> V_17 = V_5 -> V_12 ;
V_19 -> V_20 = V_5 ;
V_19 -> V_63 = F_32 ( V_5 -> V_12 , V_5 -> V_57 ) ;
V_19 -> V_64 = 1 ;
V_62 = F_33 ( V_5 -> V_12 , 128 , V_51 ,
& V_19 -> V_65 ) ;
if ( ! V_62 ) {
F_34 ( V_19 ) ;
V_10 = - V_52 ;
goto V_53;
}
V_19 -> V_66 = V_67 | V_68 ;
V_19 -> V_38 = V_62 ;
V_19 -> V_69 = F_19 ;
V_19 -> V_70 = 8 ;
V_19 -> V_71 = 128 ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_19 -> V_72 [ V_49 ] . V_73 = V_49 * 16 ;
V_19 -> V_72 [ V_49 ] . V_74 = 16 ;
}
V_5 -> V_19 [ V_29 ] = V_19 ;
}
V_5 -> V_15 = F_31 ( 0 , V_51 ) ;
if ( ! V_5 -> V_15 ) {
V_10 = - V_52 ;
goto V_53;
}
V_5 -> V_14 [ 0 ] = 0xaa ;
V_5 -> V_14 [ 1 ] = 0x01 ;
V_5 -> V_14 [ 2 ] = 0x05 ;
V_5 -> V_14 [ 3 ] = 0x01 ;
F_35 ( V_5 -> V_15 , V_5 -> V_12 , F_36 ( V_5 -> V_12 ,
V_5 -> V_56 ) , V_5 -> V_14 , sizeof( V_5 -> V_14 ) ,
F_10 , V_5 ) ;
V_5 -> V_6 . V_75 = L_5 ;
V_5 -> V_6 . V_76 = L_6 ;
V_5 -> V_6 . V_77 = F_9 ;
V_5 -> V_6 . V_78 = F_1 ;
V_5 -> V_11 = V_5 -> V_7 = true ;
F_37 ( & V_5 -> V_13 , 0 ) ;
V_10 = F_38 ( & V_41 -> V_17 , & V_5 -> V_6 ) ;
if ( V_10 )
goto V_53;
F_39 ( V_5 -> V_12 , V_5 -> V_79 , sizeof( V_5 -> V_79 ) ) ;
V_36 -> V_80 = V_81 ;
V_36 -> V_82 = V_5 -> V_79 ;
F_40 ( V_5 -> V_12 , & V_36 -> V_83 ) ;
V_36 -> V_17 . V_84 = & V_41 -> V_17 ;
V_36 -> V_85 = V_86 ;
F_41 ( V_36 , V_87 ) ;
V_36 -> V_88 = V_5 ;
V_36 -> V_89 = V_90 ;
V_36 -> V_91 = V_92 ;
V_36 -> V_93 = F_42 ( 100 ) ;
V_36 -> V_94 = V_37 ;
V_10 = F_43 ( V_36 ) ;
if ( V_10 ) {
F_28 ( & V_41 -> V_17 , L_7 , V_10 ) ;
goto V_95;
}
F_44 ( V_41 , V_5 ) ;
for ( V_29 = 0 ; V_29 < V_61 ; V_29 ++ ) {
V_10 = F_6 ( V_5 -> V_19 [ V_29 ] , V_51 ) ;
if ( V_10 ) {
F_28 ( V_5 -> V_17 , L_8 , V_10 ) ;
goto V_96;
}
}
return 0 ;
V_96:
F_45 ( V_36 ) ;
V_36 = NULL ;
V_95:
F_46 ( & V_5 -> V_6 ) ;
V_53:
if ( V_5 ) {
for ( V_29 = 0 ; V_29 < V_61 && V_5 -> V_19 [ V_29 ] ; V_29 ++ ) {
struct V_19 * V_19 = V_5 -> V_19 [ V_29 ] ;
F_47 ( V_19 ) ;
F_48 ( V_5 -> V_12 , 128 , V_19 -> V_38 ,
V_19 -> V_65 ) ;
F_34 ( V_19 ) ;
}
F_47 ( V_5 -> V_15 ) ;
F_34 ( V_5 -> V_15 ) ;
F_49 ( V_5 ) ;
}
F_50 ( V_36 ) ;
return V_10 ;
}
static void F_51 ( struct V_40 * V_41 )
{
struct V_4 * V_5 = F_52 ( V_41 ) ;
struct V_97 * V_12 = V_5 -> V_12 ;
int V_29 ;
V_5 -> V_12 = NULL ;
F_45 ( V_5 -> V_36 ) ;
F_46 ( & V_5 -> V_6 ) ;
for ( V_29 = 0 ; V_29 < V_61 ; V_29 ++ ) {
F_47 ( V_5 -> V_19 [ V_29 ] ) ;
F_48 ( V_12 , 128 , V_5 -> V_19 [ V_29 ] -> V_38 ,
V_5 -> V_19 [ V_29 ] -> V_65 ) ;
F_34 ( V_5 -> V_19 [ V_29 ] ) ;
}
F_47 ( V_5 -> V_15 ) ;
F_34 ( V_5 -> V_15 ) ;
F_44 ( V_41 , NULL ) ;
F_49 ( V_5 ) ;
}
static int F_53 ( struct V_40 * V_41 , T_2 V_98 )
{
struct V_4 * V_5 = F_52 ( V_41 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_61 ; V_29 ++ )
F_47 ( V_5 -> V_19 [ V_29 ] ) ;
F_54 ( & V_5 -> V_6 ) ;
F_47 ( V_5 -> V_15 ) ;
return 0 ;
}
static int F_55 ( struct V_40 * V_41 )
{
struct V_4 * V_5 = F_52 ( V_41 ) ;
int V_29 , V_36 ;
V_5 -> V_11 = true ;
F_56 ( & V_5 -> V_6 ) ;
for ( V_29 = 0 ; V_29 < V_61 ; V_29 ++ ) {
V_36 = F_6 ( V_5 -> V_19 [ V_29 ] , V_51 ) ;
if ( V_36 ) {
F_7 ( V_5 -> V_17 , L_9 , V_36 ) ;
break;
}
}
return V_36 ;
}
