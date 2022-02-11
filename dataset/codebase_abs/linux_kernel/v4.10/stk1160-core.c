int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
int V_6 = F_2 ( V_2 -> V_7 , 0 ) ;
T_2 * V_8 ;
* V_4 = 0 ;
V_8 = F_3 ( sizeof( T_2 ) , V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_5 = F_4 ( V_2 -> V_7 , V_6 , 0x00 ,
V_11 | V_12 | V_13 ,
0x00 , V_3 , V_8 , sizeof( T_2 ) , V_14 ) ;
if ( V_5 < 0 ) {
F_5 ( L_1 ,
V_3 , V_5 ) ;
F_6 ( V_8 ) ;
return V_5 ;
}
* V_4 = * V_8 ;
F_6 ( V_8 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
int V_6 = F_8 ( V_2 -> V_7 , 0 ) ;
V_5 = F_4 ( V_2 -> V_7 , V_6 , 0x01 ,
V_15 | V_12 | V_13 ,
V_4 , V_3 , NULL , 0 , V_14 ) ;
if ( V_5 < 0 ) {
F_5 ( L_2 ,
V_3 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
int V_16 ;
static const T_2 V_17 [] = {
0x98 , 0x90 , 0x88 , 0x80 , 0x98
} ;
if ( V_2 -> V_18 == V_19 )
V_16 = V_20 ;
else
V_16 = V_21 ;
if ( V_2 -> V_18 < F_10 ( V_17 ) ) {
F_11 ( & V_2 -> V_22 , 0 , V_23 , V_24 ,
V_16 , 0 , 0 ) ;
F_7 ( V_2 , V_25 , V_17 [ V_2 -> V_18 ] ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
int V_26 ;
static const struct V_27 V_28 [] = {
{ V_25 + 2 , 0x0078 } ,
{ V_29 + 1 , 0x0000 } ,
{ V_29 + 3 , 0x0002 } ,
{ V_30 , 0x0010 } ,
{ V_30 + 1 , 0x0000 } ,
{ V_30 + 2 , 0x0014 } ,
{ V_30 + 3 , 0x000E } ,
{ V_31 , 0x0046 } ,
{ V_32 , 0x0012 } ,
{ V_33 , 0x002D } ,
{ V_33 + 1 , 0x0001 } ,
{ V_33 + 2 , 0x0000 } ,
{ V_33 + 3 , 0x0000 } ,
{ V_32 , 0x0080 } ,
{ 0xffff , 0xffff }
} ;
for ( V_26 = 0 ; V_28 [ V_26 ] . V_3 != 0xffff ; V_26 ++ )
F_7 ( V_2 , V_28 [ V_26 ] . V_3 , V_28 [ V_26 ] . V_34 ) ;
}
static void F_13 ( struct V_35 * V_22 )
{
struct V_1 * V_2 = F_14 ( V_22 , struct V_1 , V_22 ) ;
F_15 ( L_3 ) ;
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_36 ) ;
F_18 ( & V_2 -> V_22 ) ;
F_6 ( V_2 -> V_37 ) ;
F_6 ( V_2 ) ;
}
static int F_19 ( struct V_38 * V_39 , struct V_40 * V_7 ,
unsigned int * V_41 )
{
int V_26 , V_42 , V_43 , V_44 , V_45 ;
const struct V_46 * V_47 ;
bool V_48 = false , V_49 = false ;
const char * V_50 ;
V_45 = V_39 -> V_51 [ 0 ] . V_47 . V_52 ;
for ( V_26 = 0 ; V_26 < V_39 -> V_53 ; V_26 ++ ) {
for ( V_42 = 0 ; V_42 < V_39 -> V_51 [ V_26 ] . V_47 . V_54 ; V_42 ++ ) {
V_47 = & V_39 -> V_51 [ V_26 ] . V_55 [ V_42 ] . V_47 ;
V_43 = F_20 ( V_47 -> V_56 ) ;
V_44 = V_43 & 0x7ff ;
if ( V_7 -> V_50 == V_57 )
V_44 = V_44 * F_21 ( V_43 ) ;
if ( F_22 ( V_47 ) &&
F_23 ( V_47 ) ) {
switch ( V_47 -> V_58 ) {
case V_59 :
V_49 = true ;
break;
case V_60 :
V_48 = true ;
V_41 [ V_26 ] = V_44 ;
break;
}
}
}
}
if ( ! ( V_49 || V_48 ) ) {
F_24 ( & V_7 -> V_2 , L_4 ) ;
return - V_61 ;
}
switch ( V_7 -> V_50 ) {
case V_62 :
V_50 = L_5 ;
break;
case V_63 :
V_50 = L_6 ;
break;
case V_57 :
V_50 = L_7 ;
break;
default:
V_50 = L_8 ;
}
F_25 ( & V_7 -> V_2 , L_9 ,
V_7 -> V_64 ? V_7 -> V_64 : L_10 ,
V_7 -> V_65 ? V_7 -> V_65 : L_10 ,
V_50 ,
F_20 ( V_7 -> V_66 . V_67 ) ,
F_20 ( V_7 -> V_66 . V_68 ) ,
V_45 ,
V_39 -> V_51 -> V_47 . V_52 ) ;
if ( V_49 )
F_26 ( & V_7 -> V_2 , L_11 , V_45 ) ;
if ( V_48 )
F_25 ( & V_7 -> V_2 , L_12 ,
V_45 ) ;
if ( V_7 -> V_50 != V_57 )
F_26 ( & V_7 -> V_2 , L_13 ) ;
return 0 ;
}
static int F_27 ( struct V_38 * V_69 ,
const struct V_70 * V_71 )
{
int V_72 = 0 ;
unsigned int * V_37 ;
struct V_40 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_28 ( V_69 ) ;
if ( V_69 -> V_51 [ 0 ] . V_47 . V_73 == V_74 )
return - V_61 ;
V_37 = F_3 ( sizeof( V_37 [ 0 ] ) *
V_69 -> V_53 , V_9 ) ;
if ( V_37 == NULL )
return - V_10 ;
V_72 = F_19 ( V_69 , V_7 , V_37 ) ;
if ( V_72 < 0 ) {
F_6 ( V_37 ) ;
return V_72 ;
}
V_2 = F_29 ( sizeof( struct V_1 ) , V_9 ) ;
if ( V_2 == NULL ) {
F_6 ( V_37 ) ;
return - V_10 ;
}
V_2 -> V_37 = V_37 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_75 = V_69 -> V_53 ;
V_2 -> V_18 = V_76 ;
V_2 -> V_2 = & V_69 -> V_2 ;
F_30 ( V_69 , V_2 ) ;
V_72 = F_31 ( V_2 ) ;
if ( V_72 < 0 )
goto V_77;
F_32 ( & V_2 -> V_78 ) ;
F_33 ( & V_2 -> V_79 ) ;
F_33 ( & V_2 -> V_80 ) ;
V_72 = F_34 ( & V_2 -> V_36 , 0 ) ;
if ( V_72 ) {
F_5 ( L_14 , V_72 ) ;
goto V_77;
}
V_2 -> V_22 . V_81 = F_13 ;
V_2 -> V_22 . V_36 = & V_2 -> V_36 ;
V_72 = F_35 ( V_2 -> V_2 , & V_2 -> V_22 ) ;
if ( V_72 ) {
F_5 ( L_15 , V_72 ) ;
goto V_82;
}
V_72 = F_36 ( V_2 ) ;
if ( V_72 < 0 )
goto V_83;
V_2 -> V_84 = F_37 ( & V_2 -> V_22 , & V_2 -> V_85 ,
L_16 , 0 , V_86 ) ;
F_11 ( & V_2 -> V_22 , 0 , V_87 , V_88 , 0 ) ;
F_11 ( & V_2 -> V_22 , 0 , V_23 , V_89 , 0 ) ;
F_12 ( V_2 ) ;
F_9 ( V_2 ) ;
F_38 ( V_2 ) ;
V_72 = F_39 ( V_2 ) ;
if ( V_72 < 0 )
goto V_90;
return 0 ;
V_90:
F_16 ( V_2 ) ;
V_83:
F_18 ( & V_2 -> V_22 ) ;
V_82:
F_17 ( & V_2 -> V_36 ) ;
V_77:
F_6 ( V_37 ) ;
F_6 ( V_2 ) ;
return V_72 ;
}
static void F_40 ( struct V_38 * V_69 )
{
struct V_1 * V_2 ;
V_2 = F_41 ( V_69 ) ;
F_30 ( V_69 , NULL ) ;
F_42 ( & V_2 -> V_80 ) ;
F_42 ( & V_2 -> V_79 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( & V_2 -> V_91 ) ;
F_47 ( & V_2 -> V_22 ) ;
V_2 -> V_7 = NULL ;
F_48 ( & V_2 -> V_79 ) ;
F_48 ( & V_2 -> V_80 ) ;
F_49 ( & V_2 -> V_22 ) ;
}
