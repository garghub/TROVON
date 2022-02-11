static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
int V_6 ;
T_1 V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 = V_9 -> V_10 -> V_11 ( & V_9 -> V_12 , V_9 -> V_13 , V_3 , & V_7 ) ;
if ( V_6 < 0 )
goto V_14;
V_7 = ( ( V_7 & ( ~ V_4 ) ) | ( ( V_5 << F_3 ( V_4 ) ) & V_4 ) ) ;
V_6 = V_9 -> V_10 -> V_15 ( & V_9 -> V_12 , V_9 -> V_13 , V_3 , V_7 ) ;
V_14:
return V_6 ;
}
static int F_4 ( struct V_16 * V_17 ,
unsigned int V_18 , struct V_19 * V_20 )
{
int V_21 , V_22 = - V_23 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( V_17 -> V_18 . V_25 [ V_21 ] . V_26 == 0 )
goto V_27;
if ( V_17 -> V_18 . V_25 [ V_21 ] . V_26 == V_18 ) {
V_20 -> V_26 = V_17 -> V_18 . V_25 [ V_21 ] . V_26 ;
V_20 -> V_28 = V_17 -> V_18 . V_25 [ V_21 ] . V_28 ;
V_22 = 0 ;
break;
}
}
V_27:
return V_22 ;
}
int F_5 ( struct V_1 * V_2 , unsigned int V_18 )
{
int V_6 ;
struct V_19 V_20 = { 0 , 0 } ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 = F_4 ( V_9 -> V_17 , V_18 , & V_20 ) ;
if ( V_6 < 0 )
goto V_27;
if ( ( V_9 -> V_17 -> V_18 . V_29 == V_9 -> V_17 -> V_30 . V_29 ) &&
( V_9 -> V_17 -> V_18 . V_4 == V_9 -> V_17 -> V_30 . V_4 ) ) {
if ( V_9 -> V_31 == true ) {
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_18 . V_29 ,
V_9 -> V_17 -> V_18 . V_4 ,
V_20 . V_28 ) ;
} else {
V_6 = 0 ;
}
} else {
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_18 . V_29 , V_9 -> V_17 -> V_18 . V_4 ,
V_20 . V_28 ) ;
}
if ( V_6 >= 0 )
V_9 -> V_18 = V_20 . V_26 ;
V_27:
return V_6 ;
}
static int F_6 ( struct V_16 * V_17 ,
unsigned int V_32 , int * V_33 )
{
int V_21 , V_22 = - V_23 ;
for ( V_21 = 0 ; V_21 < V_34 ; V_21 ++ ) {
if ( V_17 -> V_32 . V_35 [ V_21 ] . V_36 == 0 )
goto V_27;
if ( V_17 -> V_32 . V_35 [ V_21 ] . V_36 == V_32 ) {
* V_33 = V_21 ;
V_22 = 0 ;
break;
}
}
V_27:
return V_22 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_32 )
{
int V_6 , V_21 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 = F_6 ( V_9 -> V_17 , V_32 , & V_21 ) ;
if ( V_6 < 0 )
goto V_37;
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_32 . V_29 ,
V_9 -> V_17 -> V_32 . V_4 ,
V_9 -> V_17 -> V_32 . V_35 [ V_21 ] . V_28 ) ;
if ( V_6 < 0 )
goto V_37;
V_9 -> V_38 = (struct V_39 * )
& V_9 -> V_17 -> V_32 . V_35 [ V_21 ] ;
return V_6 ;
V_37:
F_8 ( & V_2 -> V_13 , L_1 ) ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 , bool V_40 )
{
T_1 V_41 ;
int V_6 = - V_23 ;
bool V_42 = false ;
struct V_19 V_20 = { 0 , 0 } ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_40 ) {
V_41 = V_9 -> V_17 -> V_30 . V_43 ;
if ( ( V_9 -> V_17 -> V_18 . V_29 == V_9 -> V_17 -> V_30 . V_29 ) &&
( V_9 -> V_17 -> V_18 . V_4 == V_9 -> V_17 -> V_30 . V_4 ) ) {
V_6 = F_4 ( V_9 -> V_17 ,
V_9 -> V_18 , & V_20 ) ;
if ( V_6 < 0 )
goto V_44;
V_41 = V_20 . V_28 ;
V_42 = true ;
}
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_30 . V_29 ,
V_9 -> V_17 -> V_30 . V_4 , V_41 ) ;
if ( V_6 < 0 )
goto V_44;
V_9 -> V_31 = true ;
if ( V_42 )
V_9 -> V_18 = V_20 . V_26 ;
} else {
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_30 . V_29 ,
V_9 -> V_17 -> V_30 . V_4 ,
V_9 -> V_17 -> V_30 . V_45 ) ;
if ( V_6 < 0 )
goto V_44;
V_9 -> V_31 = false ;
}
V_44:
return V_6 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_46 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_1 ( V_2 ,
V_9 -> V_17 -> V_47 . V_29 ,
V_9 -> V_17 -> V_47 . V_4 , V_46 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_12 ( & V_9 -> V_12 . V_48 ) ;
V_6 = F_9 ( V_2 , false ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_7 ( V_2 ,
V_9 -> V_38 -> V_36 ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_5 ( V_2 , V_9 -> V_18 ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_50 . V_29 , V_9 -> V_17 -> V_50 . V_4 , true ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_10 ( V_2 , V_51 ) ;
V_49:
return V_6 ;
}
int F_13 ( struct V_1 * V_2 , bool V_40 )
{
int V_6 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_17 -> V_52 . V_53 . V_54 > 0 ) {
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_52 . V_53 . V_54 ,
V_9 -> V_17 -> V_52 . V_53 . V_55 , ( int ) V_40 ) ;
if ( V_6 < 0 )
goto V_56;
}
V_6 = F_1 ( V_2 ,
V_9 -> V_17 -> V_52 . V_29 ,
V_9 -> V_17 -> V_52 . V_4 , ( int ) V_40 ) ;
V_56:
return V_6 ;
}
int F_14 ( struct V_1 * V_2 , int V_57 )
{
int V_6 = - V_23 , V_21 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < V_34 ; V_21 ++ ) {
if ( ( V_9 -> V_17 -> V_32 . V_35 [ V_21 ] . V_58 == V_57 ) &&
( V_9 -> V_17 -> V_32 . V_35 [ V_21 ] . V_58 != 0 ) ) {
V_6 = 0 ;
break;
}
}
if ( V_6 < 0 )
goto V_59;
V_6 = F_7 ( V_2 ,
V_9 -> V_17 -> V_32 . V_35 [ V_21 ] . V_36 ) ;
V_59:
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_60 , int * V_5 )
{
int V_6 ;
T_1 V_61 [ V_62 ] ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 = V_9 -> V_10 -> V_63 ( & V_9 -> V_12 , V_9 -> V_13 ,
V_60 , V_62 ,
V_61 , V_9 -> V_64 ) ;
if ( V_6 < 0 )
goto V_65;
* V_5 = ( V_66 ) F_16 ( V_61 ) ;
V_65:
return V_6 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_67 const * V_68 , int * V_69 )
{
int V_6 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_18 ( & V_2 -> V_70 ) ;
if ( V_2 -> V_71 == V_72 ) {
V_6 = - V_73 ;
goto V_65;
} else {
V_6 = F_9 ( V_2 , true ) ;
if ( V_6 < 0 )
goto V_65;
F_19 ( ( V_9 -> V_17 -> V_74 * 1000 ) / V_9 -> V_18 ) ;
V_6 = F_15 ( V_2 , V_68 -> V_75 , V_69 ) ;
if ( V_6 < 0 )
goto V_65;
* V_69 = * V_69 >> V_68 -> V_76 . V_77 ;
}
F_20 ( & V_2 -> V_70 ) ;
return V_6 ;
V_65:
F_20 ( & V_2 -> V_70 ) ;
return V_6 ;
}
int F_21 ( struct V_1 * V_2 ,
int V_78 , const struct V_16 * V_79 )
{
T_1 V_80 ;
int V_21 , V_81 , V_6 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 = V_9 -> V_10 -> V_11 ( & V_9 -> V_12 , V_9 -> V_13 ,
V_82 , & V_80 ) ;
if ( V_6 < 0 ) {
F_8 ( & V_2 -> V_13 , L_2 ) ;
goto V_83;
}
for ( V_21 = 0 ; V_21 < V_78 ; V_21 ++ ) {
if ( V_79 [ V_21 ] . V_80 == V_80 )
break;
}
if ( V_21 == V_78 )
goto V_84;
for ( V_81 = 0 ; V_81 < F_22 ( V_79 [ V_21 ] . V_85 ) ; V_81 ++ ) {
if ( strcmp ( V_2 -> V_86 ,
& V_79 [ V_21 ] . V_85 [ V_81 ] [ 0 ] ) == 0 )
break;
}
if ( V_81 == F_22 ( V_79 [ V_21 ] . V_85 ) ) {
F_8 ( & V_2 -> V_13 , L_3 ) ;
goto V_87;
}
V_9 -> V_17 = (struct V_16 * ) & V_79 [ V_21 ] ;
return V_21 ;
V_84:
F_8 ( & V_2 -> V_13 , L_4 , V_80 ) ;
V_87:
V_6 = - V_88 ;
V_83:
return V_6 ;
}
T_2 F_23 ( struct V_89 * V_13 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_8 * V_93 = F_2 ( F_24 ( V_13 ) ) ;
return sprintf ( V_92 , L_5 , V_93 -> V_18 ) ;
}
T_2 F_25 ( struct V_89 * V_13 ,
struct V_90 * V_91 , const char * V_92 , T_3 V_94 )
{
int V_6 ;
unsigned int V_18 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_6 = F_26 ( V_92 , 10 , & V_18 ) ;
if ( V_6 < 0 )
goto V_95;
F_18 ( & V_2 -> V_70 ) ;
V_6 = F_5 ( V_2 , V_18 ) ;
F_20 ( & V_2 -> V_70 ) ;
V_95:
return V_6 < 0 ? V_6 : V_94 ;
}
T_2 F_27 ( struct V_89 * V_13 ,
struct V_90 * V_91 , char * V_92 )
{
int V_21 , V_96 = 0 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_18 ( & V_2 -> V_70 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( V_9 -> V_17 -> V_18 . V_25 [ V_21 ] . V_26 == 0 )
break;
V_96 += F_28 ( V_92 + V_96 , V_97 - V_96 , L_6 ,
V_9 -> V_17 -> V_18 . V_25 [ V_21 ] . V_26 ) ;
}
F_20 ( & V_2 -> V_70 ) ;
V_92 [ V_96 - 1 ] = '\n' ;
return V_96 ;
}
T_2 F_29 ( struct V_89 * V_13 ,
struct V_90 * V_91 , char * V_92 )
{
int V_21 , V_96 = 0 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_18 ( & V_2 -> V_70 ) ;
for ( V_21 = 0 ; V_21 < V_34 ; V_21 ++ ) {
if ( V_9 -> V_17 -> V_32 . V_35 [ V_21 ] . V_36 == 0 )
break;
V_96 += F_28 ( V_92 + V_96 , V_97 - V_96 , L_7 ,
V_9 -> V_17 -> V_32 . V_35 [ V_21 ] . V_58 ) ;
}
F_20 ( & V_2 -> V_70 ) ;
V_92 [ V_96 - 1 ] = '\n' ;
return V_96 ;
}
