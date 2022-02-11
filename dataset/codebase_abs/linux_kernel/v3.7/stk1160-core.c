int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
int V_6 = F_2 ( V_2 -> V_7 , 0 ) ;
* V_4 = 0 ;
V_5 = F_3 ( V_2 -> V_7 , V_6 , 0x00 ,
V_8 | V_9 | V_10 ,
0x00 , V_3 , V_4 , sizeof( T_2 ) , V_11 ) ;
if ( V_5 < 0 ) {
F_4 ( L_1 ,
V_3 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
int V_6 = F_6 ( V_2 -> V_7 , 0 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_6 , 0x01 ,
V_12 | V_9 | V_10 ,
V_4 , V_3 , NULL , 0 , V_11 ) ;
if ( V_5 < 0 ) {
F_4 ( L_2 ,
V_3 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_13 ;
static const T_2 V_14 [] = {
0x98 , 0x90 , 0x88 , 0x80 , 0x98
} ;
if ( V_2 -> V_15 == V_16 )
V_13 = V_17 ;
else
V_13 = V_18 ;
if ( V_2 -> V_15 < F_8 ( V_14 ) ) {
F_9 ( & V_2 -> V_19 , 0 , V_20 , V_21 ,
V_13 , 0 , 0 ) ;
F_5 ( V_2 , V_22 , V_14 [ V_2 -> V_15 ] ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
int V_23 ;
static const struct V_24 V_25 [] = {
{ V_22 + 2 , 0x0078 } ,
{ V_26 + 1 , 0x0000 } ,
{ V_26 + 3 , 0x0002 } ,
{ V_27 , 0x0010 } ,
{ V_27 + 1 , 0x0000 } ,
{ V_27 + 2 , 0x0014 } ,
{ V_27 + 3 , 0x000E } ,
{ V_28 , 0x0046 } ,
{ V_29 , 0x0012 } ,
{ V_30 , 0x002D } ,
{ V_30 + 1 , 0x0001 } ,
{ V_30 + 2 , 0x0000 } ,
{ V_30 + 3 , 0x0000 } ,
{ V_29 , 0x0080 } ,
{ 0xffff , 0xffff }
} ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_3 != 0xffff ; V_23 ++ )
F_5 ( V_2 , V_25 [ V_23 ] . V_3 , V_25 [ V_23 ] . V_31 ) ;
}
static void F_11 ( struct V_32 * V_19 )
{
struct V_1 * V_2 = F_12 ( V_19 , struct V_1 , V_19 ) ;
F_13 ( L_3 ) ;
F_14 ( V_2 ) ;
F_15 ( & V_2 -> V_33 ) ;
F_16 ( & V_2 -> V_19 ) ;
F_17 ( V_2 -> V_34 ) ;
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_35 * V_36 , struct V_37 * V_7 ,
unsigned int * V_38 )
{
int V_23 , V_39 , V_40 , V_41 , V_42 ;
const struct V_43 * V_44 ;
bool V_45 = false , V_46 = false ;
const char * V_47 ;
V_42 = V_36 -> V_48 [ 0 ] . V_44 . V_49 ;
for ( V_23 = 0 ; V_23 < V_36 -> V_50 ; V_23 ++ ) {
for ( V_39 = 0 ; V_39 < V_36 -> V_48 [ V_23 ] . V_44 . V_51 ; V_39 ++ ) {
V_44 = & V_36 -> V_48 [ V_23 ] . V_52 [ V_39 ] . V_44 ;
V_40 = F_19 ( V_44 -> V_53 ) ;
V_41 = V_40 & 0x7ff ;
if ( V_7 -> V_47 == V_54 )
V_41 = V_41 * F_20 ( V_40 ) ;
if ( F_21 ( V_44 ) &&
F_22 ( V_44 ) ) {
switch ( V_44 -> V_55 ) {
case V_56 :
V_46 = true ;
break;
case V_57 :
V_45 = true ;
V_38 [ V_23 ] = V_41 ;
break;
}
}
}
}
if ( ! ( V_46 || V_45 ) ) {
F_23 ( & V_7 -> V_2 , L_4 ) ;
return - V_58 ;
}
switch ( V_7 -> V_47 ) {
case V_59 :
V_47 = L_5 ;
break;
case V_60 :
V_47 = L_6 ;
break;
case V_54 :
V_47 = L_7 ;
break;
default:
V_47 = L_8 ;
}
F_24 ( & V_7 -> V_2 , L_9 ,
V_7 -> V_61 ? V_7 -> V_61 : L_10 ,
V_7 -> V_62 ? V_7 -> V_62 : L_10 ,
V_47 ,
F_19 ( V_7 -> V_63 . V_64 ) ,
F_19 ( V_7 -> V_63 . V_65 ) ,
V_42 ,
V_36 -> V_48 -> V_44 . V_49 ) ;
if ( V_46 )
F_25 ( & V_7 -> V_2 , L_11 , V_42 ) ;
if ( V_45 )
F_24 ( & V_7 -> V_2 , L_12 ,
V_42 ) ;
if ( V_7 -> V_47 != V_54 )
F_25 ( & V_7 -> V_2 , L_13 ) ;
return 0 ;
}
static int F_26 ( struct V_35 * V_66 ,
const struct V_67 * V_68 )
{
int V_69 = 0 ;
unsigned int * V_34 ;
struct V_37 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_27 ( V_66 ) ;
if ( V_66 -> V_48 [ 0 ] . V_44 . V_70 == V_71 )
return - V_58 ;
V_34 = F_28 ( sizeof( V_34 [ 0 ] ) *
V_66 -> V_50 , V_72 ) ;
if ( V_34 == NULL )
return - V_73 ;
V_69 = F_18 ( V_66 , V_7 , V_34 ) ;
if ( V_69 < 0 ) {
F_17 ( V_34 ) ;
return V_69 ;
}
V_2 = F_29 ( sizeof( struct V_1 ) , V_72 ) ;
if ( V_2 == NULL ) {
F_17 ( V_34 ) ;
return - V_73 ;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_74 = V_66 -> V_50 ;
V_2 -> V_15 = V_75 ;
V_2 -> V_2 = & V_66 -> V_2 ;
F_30 ( V_66 , V_2 ) ;
V_69 = F_31 ( V_2 ) ;
if ( V_69 < 0 )
goto V_76;
F_32 ( & V_2 -> V_77 ) ;
F_33 ( & V_2 -> V_78 ) ;
F_33 ( & V_2 -> V_79 ) ;
V_69 = F_34 ( & V_2 -> V_33 , 0 ) ;
if ( V_69 ) {
F_4 ( L_14 , V_69 ) ;
goto V_76;
}
V_2 -> V_19 . V_80 = F_11 ;
V_2 -> V_19 . V_33 = & V_2 -> V_33 ;
V_69 = F_35 ( V_2 -> V_2 , & V_2 -> V_19 ) ;
if ( V_69 ) {
F_4 ( L_15 , V_69 ) ;
goto V_81;
}
V_69 = F_36 ( V_2 ) ;
if ( V_69 < 0 )
goto V_82;
V_2 -> V_83 = F_37 ( & V_2 -> V_19 , & V_2 -> V_84 ,
L_16 , 0 , V_85 ) ;
F_13 ( L_17 ,
V_86 ) ;
F_9 ( & V_2 -> V_19 , 0 , V_87 , V_88 , 0 ) ;
F_9 ( & V_2 -> V_19 , 0 , V_20 , V_89 , 0 ) ;
F_10 ( V_2 ) ;
F_7 ( V_2 ) ;
F_38 ( V_2 ) ;
V_69 = F_39 ( V_2 ) ;
if ( V_69 < 0 )
goto V_90;
return 0 ;
V_90:
F_14 ( V_2 ) ;
V_82:
F_16 ( & V_2 -> V_19 ) ;
V_81:
F_15 ( & V_2 -> V_33 ) ;
V_76:
F_17 ( V_34 ) ;
F_17 ( V_2 ) ;
return V_69 ;
}
static void F_40 ( struct V_35 * V_66 )
{
struct V_1 * V_2 ;
V_2 = F_41 ( V_66 ) ;
F_30 ( V_66 , NULL ) ;
F_42 ( & V_2 -> V_79 ) ;
F_42 ( & V_2 -> V_78 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( & V_2 -> V_91 ) ;
F_47 ( & V_2 -> V_19 ) ;
V_2 -> V_7 = NULL ;
F_48 ( & V_2 -> V_78 ) ;
F_48 ( & V_2 -> V_79 ) ;
F_49 ( & V_2 -> V_19 ) ;
}
