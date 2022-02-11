static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = (struct V_2 * ) V_1 ;
V_5 = V_3 -> V_6 ;
F_2 ( V_3 , V_5 -> V_7 , V_5 -> V_8 ) ;
}
static void F_3 ( struct V_2 * V_3 , int V_9 ,
int V_10 , int V_11 )
{
}
static void * F_4 ( T_1 V_12 )
{
return ( void * ) ( V_13 ) V_12 ;
}
static T_1 F_5 ( void * V_12 )
{
return ( T_1 ) ( V_13 ) V_12 ;
}
static int F_6 ( struct V_2 * V_3 , int V_9 ,
int V_14 )
{
struct V_4 * V_5 ;
V_5 = V_3 -> V_6 ;
F_7 ( & V_5 -> V_15 ) ;
V_5 -> V_7 = V_9 ;
V_5 -> V_8 = V_14 ;
F_8 ( & V_5 -> V_16 ) ;
F_9 ( & V_5 -> V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 , int V_19 ,
unsigned long long V_20 , unsigned long long V_21 ,
T_1 V_22 , T_2 V_23 , T_2 V_24 )
{
unsigned int V_25 , V_26 = 0 ;
unsigned long long V_27 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_18 -> V_28 ;
V_5 = V_3 -> V_6 ;
V_25 = V_18 -> V_29 ;
switch ( V_23 ) {
case V_30 :
V_26 = 0x10 ;
break;
case V_31 :
V_26 = 0x1000 ;
break;
case V_32 :
V_26 = 0x10000 ;
break;
case V_33 :
V_26 = 0x10000 ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
default:
F_11 ( L_1 ) ;
return - V_39 ;
}
V_27 = V_20 + V_21 - V_26 ;
if ( V_20 & ( V_26 - 1 ) ) {
F_11 ( L_2 ) ;
return - V_39 ;
}
if ( V_27 & ( V_26 - 1 ) ) {
F_11 ( L_3 ) ;
return - V_39 ;
}
F_7 ( & V_18 -> V_40 ) ;
V_5 -> V_41 [ V_25 ] . V_19 = V_19 ;
V_5 -> V_41 [ V_25 ] . V_20 = V_20 ;
V_5 -> V_41 [ V_25 ] . V_21 = V_21 ;
V_5 -> V_41 [ V_25 ] . V_22 = F_4 ( V_22 ) ;
V_5 -> V_41 [ V_25 ] . V_23 = V_23 ;
V_5 -> V_41 [ V_25 ] . V_24 = V_24 ;
F_9 ( & V_18 -> V_40 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , int * V_19 ,
unsigned long long * V_20 , unsigned long long * V_21 ,
T_1 * V_22 , T_2 * V_23 , T_2 * V_24 )
{
unsigned int V_25 ;
struct V_4 * V_5 ;
V_5 = V_18 -> V_28 -> V_6 ;
V_25 = V_18 -> V_29 ;
F_7 ( & V_18 -> V_40 ) ;
* V_19 = V_5 -> V_41 [ V_25 ] . V_19 ;
* V_20 = V_5 -> V_41 [ V_25 ] . V_20 ;
* V_21 = V_5 -> V_41 [ V_25 ] . V_21 ;
* V_22 = F_5 ( V_5 -> V_41 [ V_25 ] . V_22 ) ;
* V_23 = V_5 -> V_41 [ V_25 ] . V_23 ;
* V_24 = V_5 -> V_41 [ V_25 ] . V_24 ;
F_9 ( & V_18 -> V_40 ) ;
return 0 ;
}
static int F_13 ( struct V_42 * V_18 , int V_19 ,
unsigned long long V_20 , unsigned long long V_21 ,
T_2 V_23 , T_2 V_24 , T_2 V_43 )
{
int V_44 = 0 ;
unsigned int V_25 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_18 -> V_28 ;
V_5 = V_3 -> V_6 ;
if ( V_20 & 0xFFFF ) {
F_11 ( L_4 ) ;
V_44 = - V_39 ;
goto V_45;
}
if ( V_21 & 0xFFFF ) {
F_11 ( L_5 ) ;
V_44 = - V_39 ;
goto V_45;
}
if ( ( V_21 == 0 ) && ( V_19 != 0 ) ) {
F_11 ( L_6 ) ;
V_44 = - V_39 ;
goto V_45;
}
switch ( V_43 ) {
case V_46 :
case V_47 :
case V_48 :
break;
default:
F_11 ( L_7 ) ;
V_44 = - V_39 ;
goto V_49;
}
switch ( V_23 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
break;
default:
F_11 ( L_1 ) ;
V_44 = - V_39 ;
goto V_50;
}
F_14 ( & V_18 -> V_51 ) ;
V_25 = V_18 -> V_29 ;
V_5 -> V_52 [ V_25 ] . V_19 = V_19 ;
V_5 -> V_52 [ V_25 ] . V_20 = V_20 ;
V_5 -> V_52 [ V_25 ] . V_21 = V_21 ;
V_5 -> V_52 [ V_25 ] . V_23 = V_23 ;
V_5 -> V_52 [ V_25 ] . V_24 = V_24 ;
V_5 -> V_52 [ V_25 ] . V_43 = V_43 ;
F_15 ( & V_18 -> V_51 ) ;
return 0 ;
V_50:
V_49:
V_45:
return V_44 ;
}
static int F_16 ( struct V_42 * V_18 , int * V_19 ,
unsigned long long * V_20 , unsigned long long * V_21 ,
T_2 * V_23 , T_2 * V_24 , T_2 * V_43 )
{
unsigned int V_25 ;
struct V_4 * V_5 ;
V_5 = V_18 -> V_28 -> V_6 ;
V_25 = V_18 -> V_29 ;
* V_19 = V_5 -> V_52 [ V_25 ] . V_19 ;
* V_20 = V_5 -> V_52 [ V_25 ] . V_20 ;
* V_21 = V_5 -> V_52 [ V_25 ] . V_21 ;
* V_23 = V_5 -> V_52 [ V_25 ] . V_23 ;
* V_24 = V_5 -> V_52 [ V_25 ] . V_24 ;
* V_43 = V_5 -> V_52 [ V_25 ] . V_43 ;
return 0 ;
}
static int F_17 ( struct V_42 * V_18 , int * V_19 ,
unsigned long long * V_20 , unsigned long long * V_21 ,
T_2 * V_23 , T_2 * V_24 , T_2 * V_43 )
{
int V_44 ;
F_14 ( & V_18 -> V_51 ) ;
V_44 = F_16 ( V_18 , V_19 , V_20 , V_21 , V_23 ,
V_24 , V_43 ) ;
F_15 ( & V_18 -> V_51 ) ;
return V_44 ;
}
static void F_18 ( struct V_4 * V_5 , unsigned long long V_12 ,
T_2 V_23 , T_2 V_24 )
{
struct V_2 * V_3 ;
unsigned long long V_53 ;
T_2 V_54 , V_55 ;
int V_25 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = NULL , * V_60 ;
V_3 = V_5 -> V_28 ;
F_19 (pos, n, &fake_bridge->lm_resources) {
V_57 = F_20 ( V_59 , struct V_56 , V_61 ) ;
if ( V_5 -> V_62 == 0 )
return;
V_53 = V_5 -> V_53 ;
V_54 = V_5 -> V_54 ;
V_55 = V_5 -> V_55 ;
if ( ( V_54 == V_23 ) && ( V_55 == V_24 ) ) {
for ( V_25 = 0 ; V_25 < V_57 -> V_63 ; V_25 ++ ) {
if ( ( ( V_53 + ( 8 * V_25 ) ) <= V_12 ) &&
( ( V_53 + ( 8 * V_25 ) + 8 ) > V_12 ) ) {
if ( V_5 -> V_64 [ V_25 ] != NULL )
V_5 -> V_64 [ V_25 ] (
V_5 -> V_65 [ V_25 ] ) ;
}
}
}
}
}
static T_3 F_21 ( struct V_4 * V_5 , unsigned long long V_12 ,
T_2 V_23 , T_2 V_24 )
{
T_3 V_44 = 0xff ;
int V_25 ;
unsigned long long V_66 , V_67 , V_68 ;
T_3 * V_69 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
V_66 = V_5 -> V_41 [ V_25 ] . V_20 ;
V_67 = V_5 -> V_41 [ V_25 ] . V_20 + V_5 -> V_41 [ V_25 ] . V_21 ;
if ( V_23 != V_5 -> V_41 [ V_25 ] . V_23 )
continue;
if ( V_24 != V_5 -> V_41 [ V_25 ] . V_24 )
continue;
if ( ( V_12 >= V_66 ) && ( V_12 < V_67 ) ) {
V_68 = V_12 - V_5 -> V_41 [ V_25 ] . V_20 ;
V_69 = ( T_3 * ) ( V_5 -> V_41 [ V_25 ] . V_22 + V_68 ) ;
V_44 = * V_69 ;
break;
}
}
F_18 ( V_5 , V_12 , V_23 , V_24 ) ;
return V_44 ;
}
static T_4 F_22 ( struct V_4 * V_5 , unsigned long long V_12 ,
T_2 V_23 , T_2 V_24 )
{
T_4 V_44 = 0xffff ;
int V_25 ;
unsigned long long V_66 , V_67 , V_68 ;
T_4 * V_69 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
if ( V_23 != V_5 -> V_41 [ V_25 ] . V_23 )
continue;
if ( V_24 != V_5 -> V_41 [ V_25 ] . V_24 )
continue;
V_66 = V_5 -> V_41 [ V_25 ] . V_20 ;
V_67 = V_5 -> V_41 [ V_25 ] . V_20 + V_5 -> V_41 [ V_25 ] . V_21 ;
if ( ( V_12 >= V_66 ) && ( ( V_12 + 1 ) < V_67 ) ) {
V_68 = V_12 - V_5 -> V_41 [ V_25 ] . V_20 ;
V_69 = ( T_4 * ) ( V_5 -> V_41 [ V_25 ] . V_22 + V_68 ) ;
V_44 = * V_69 ;
break;
}
}
F_18 ( V_5 , V_12 , V_23 , V_24 ) ;
return V_44 ;
}
static T_2 F_23 ( struct V_4 * V_5 , unsigned long long V_12 ,
T_2 V_23 , T_2 V_24 )
{
T_2 V_44 = 0xffffffff ;
int V_25 ;
unsigned long long V_66 , V_67 , V_68 ;
T_2 * V_69 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
if ( V_23 != V_5 -> V_41 [ V_25 ] . V_23 )
continue;
if ( V_24 != V_5 -> V_41 [ V_25 ] . V_24 )
continue;
V_66 = V_5 -> V_41 [ V_25 ] . V_20 ;
V_67 = V_5 -> V_41 [ V_25 ] . V_20 + V_5 -> V_41 [ V_25 ] . V_21 ;
if ( ( V_12 >= V_66 ) && ( ( V_12 + 3 ) < V_67 ) ) {
V_68 = V_12 - V_5 -> V_41 [ V_25 ] . V_20 ;
V_69 = ( T_2 * ) ( V_5 -> V_41 [ V_25 ] . V_22 + V_68 ) ;
V_44 = * V_69 ;
break;
}
}
F_18 ( V_5 , V_12 , V_23 , V_24 ) ;
return V_44 ;
}
static T_5 F_24 ( struct V_42 * V_18 , void * V_71 ,
T_6 V_72 , T_7 V_68 )
{
int V_44 ;
T_2 V_23 , V_24 , V_43 ;
struct V_2 * V_3 ;
struct V_4 * V_73 ;
int V_25 ;
unsigned long long V_12 ;
unsigned int V_74 = 0 ;
unsigned int V_75 ;
V_3 = V_18 -> V_28 ;
V_73 = V_3 -> V_6 ;
V_25 = V_18 -> V_29 ;
V_12 = ( unsigned long long ) V_73 -> V_52 [ V_25 ] . V_20 + V_68 ;
V_23 = V_73 -> V_52 [ V_25 ] . V_23 ;
V_24 = V_73 -> V_52 [ V_25 ] . V_24 ;
V_43 = V_73 -> V_52 [ V_25 ] . V_43 ;
F_14 ( & V_18 -> V_51 ) ;
if ( V_12 & 0x1 ) {
* ( T_3 * ) V_71 = F_21 ( V_73 , V_12 , V_23 , V_24 ) ;
V_74 += 1 ;
if ( V_74 == V_72 )
goto V_76;
}
if ( ( V_43 == V_47 ) || ( V_43 == V_48 ) ) {
if ( ( V_12 + V_74 ) & 0x2 ) {
if ( ( V_72 - V_74 ) < 2 ) {
* ( T_3 * ) ( V_71 + V_74 ) = F_21 ( V_73 ,
V_12 + V_74 , V_23 , V_24 ) ;
V_74 += 1 ;
goto V_76;
} else {
* ( T_4 * ) ( V_71 + V_74 ) = F_22 ( V_73 ,
V_12 + V_74 , V_23 , V_24 ) ;
V_74 += 2 ;
}
}
}
if ( V_43 == V_48 ) {
V_75 = ( V_72 - V_74 ) & ~ 0x3 ;
while ( V_74 < V_75 ) {
* ( T_2 * ) ( V_71 + V_74 ) = F_23 ( V_73 , V_12 + V_74 ,
V_23 , V_24 ) ;
V_74 += 4 ;
}
} else if ( V_43 == V_47 ) {
V_75 = ( V_72 - V_74 ) & ~ 0x3 ;
while ( V_74 < V_75 ) {
* ( T_4 * ) ( V_71 + V_74 ) = F_22 ( V_73 , V_12 + V_74 ,
V_23 , V_24 ) ;
V_74 += 2 ;
}
} else if ( V_43 == V_46 ) {
V_75 = ( V_72 - V_74 ) ;
while ( V_74 < V_75 ) {
* ( T_3 * ) ( V_71 + V_74 ) = F_21 ( V_73 , V_12 + V_74 ,
V_23 , V_24 ) ;
V_74 += 1 ;
}
}
if ( ( V_43 == V_47 ) || ( V_43 == V_48 ) ) {
if ( ( V_72 - V_74 ) & 0x2 ) {
* ( T_4 * ) ( V_71 + V_74 ) = F_22 ( V_73 , V_12 + V_74 ,
V_23 , V_24 ) ;
V_74 += 2 ;
}
}
if ( ( V_72 - V_74 ) & 0x1 ) {
* ( T_3 * ) ( V_71 + V_74 ) = F_21 ( V_73 , V_12 + V_74 , V_23 ,
V_24 ) ;
V_74 += 1 ;
}
V_76:
V_44 = V_72 ;
F_15 ( & V_18 -> V_51 ) ;
return V_44 ;
}
static void F_25 ( struct V_4 * V_5 , T_3 * V_71 ,
unsigned long long V_12 , T_2 V_23 , T_2 V_24 )
{
int V_25 ;
unsigned long long V_66 , V_67 , V_68 ;
T_3 * V_69 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
if ( V_23 != V_5 -> V_41 [ V_25 ] . V_23 )
continue;
if ( V_24 != V_5 -> V_41 [ V_25 ] . V_24 )
continue;
V_66 = V_5 -> V_41 [ V_25 ] . V_20 ;
V_67 = V_5 -> V_41 [ V_25 ] . V_20 + V_5 -> V_41 [ V_25 ] . V_21 ;
if ( ( V_12 >= V_66 ) && ( V_12 < V_67 ) ) {
V_68 = V_12 - V_5 -> V_41 [ V_25 ] . V_20 ;
V_69 = ( T_3 * ) ( ( void * ) V_5 -> V_41 [ V_25 ] . V_22 + V_68 ) ;
* V_69 = * V_71 ;
break;
}
}
F_18 ( V_5 , V_12 , V_23 , V_24 ) ;
}
static void F_26 ( struct V_4 * V_5 , T_4 * V_71 ,
unsigned long long V_12 , T_2 V_23 , T_2 V_24 )
{
int V_25 ;
unsigned long long V_66 , V_67 , V_68 ;
T_4 * V_69 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
if ( V_23 != V_5 -> V_41 [ V_25 ] . V_23 )
continue;
if ( V_24 != V_5 -> V_41 [ V_25 ] . V_24 )
continue;
V_66 = V_5 -> V_41 [ V_25 ] . V_20 ;
V_67 = V_5 -> V_41 [ V_25 ] . V_20 + V_5 -> V_41 [ V_25 ] . V_21 ;
if ( ( V_12 >= V_66 ) && ( ( V_12 + 1 ) < V_67 ) ) {
V_68 = V_12 - V_5 -> V_41 [ V_25 ] . V_20 ;
V_69 = ( T_4 * ) ( ( void * ) V_5 -> V_41 [ V_25 ] . V_22 + V_68 ) ;
* V_69 = * V_71 ;
break;
}
}
F_18 ( V_5 , V_12 , V_23 , V_24 ) ;
}
static void F_27 ( struct V_4 * V_5 , T_2 * V_71 ,
unsigned long long V_12 , T_2 V_23 , T_2 V_24 )
{
int V_25 ;
unsigned long long V_66 , V_67 , V_68 ;
T_2 * V_69 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
if ( V_23 != V_5 -> V_41 [ V_25 ] . V_23 )
continue;
if ( V_24 != V_5 -> V_41 [ V_25 ] . V_24 )
continue;
V_66 = V_5 -> V_41 [ V_25 ] . V_20 ;
V_67 = V_5 -> V_41 [ V_25 ] . V_20 + V_5 -> V_41 [ V_25 ] . V_21 ;
if ( ( V_12 >= V_66 ) && ( ( V_12 + 3 ) < V_67 ) ) {
V_68 = V_12 - V_5 -> V_41 [ V_25 ] . V_20 ;
V_69 = ( T_2 * ) ( ( void * ) V_5 -> V_41 [ V_25 ] . V_22 + V_68 ) ;
* V_69 = * V_71 ;
break;
}
}
F_18 ( V_5 , V_12 , V_23 , V_24 ) ;
}
static T_5 F_28 ( struct V_42 * V_18 , void * V_71 ,
T_6 V_72 , T_7 V_68 )
{
int V_44 = 0 ;
T_2 V_23 , V_24 , V_43 ;
unsigned long long V_12 ;
int V_25 ;
unsigned int V_74 = 0 ;
unsigned int V_75 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_18 -> V_28 ;
V_5 = V_3 -> V_6 ;
V_25 = V_18 -> V_29 ;
V_12 = V_5 -> V_52 [ V_25 ] . V_20 + V_68 ;
V_23 = V_5 -> V_52 [ V_25 ] . V_23 ;
V_24 = V_5 -> V_52 [ V_25 ] . V_24 ;
V_43 = V_5 -> V_52 [ V_25 ] . V_43 ;
F_14 ( & V_18 -> V_51 ) ;
if ( V_12 & 0x1 ) {
F_25 ( V_5 , ( T_3 * ) V_71 , V_12 , V_23 , V_24 ) ;
V_74 += 1 ;
if ( V_74 == V_72 )
goto V_76;
}
if ( ( V_43 == V_47 ) || ( V_43 == V_48 ) ) {
if ( ( V_12 + V_74 ) & 0x2 ) {
if ( ( V_72 - V_74 ) < 2 ) {
F_25 ( V_5 , ( T_3 * ) ( V_71 + V_74 ) ,
V_12 + V_74 , V_23 , V_24 ) ;
V_74 += 1 ;
goto V_76;
} else {
F_26 ( V_5 , ( T_4 * ) ( V_71 + V_74 ) ,
V_12 + V_74 , V_23 , V_24 ) ;
V_74 += 2 ;
}
}
}
if ( V_43 == V_48 ) {
V_75 = ( V_72 - V_74 ) & ~ 0x3 ;
while ( V_74 < V_75 ) {
F_27 ( V_5 , ( T_2 * ) ( V_71 + V_74 ) ,
V_12 + V_74 , V_23 , V_24 ) ;
V_74 += 4 ;
}
} else if ( V_43 == V_47 ) {
V_75 = ( V_72 - V_74 ) & ~ 0x3 ;
while ( V_74 < V_75 ) {
F_26 ( V_5 , ( T_4 * ) ( V_71 + V_74 ) ,
V_12 + V_74 , V_23 , V_24 ) ;
V_74 += 2 ;
}
} else if ( V_43 == V_46 ) {
V_75 = ( V_72 - V_74 ) ;
while ( V_74 < V_75 ) {
F_25 ( V_5 , ( T_3 * ) ( V_71 + V_74 ) , V_12 + V_74 ,
V_23 , V_24 ) ;
V_74 += 1 ;
}
}
if ( ( V_43 == V_47 ) || ( V_43 == V_48 ) ) {
if ( ( V_72 - V_74 ) & 0x2 ) {
F_26 ( V_5 , ( T_4 * ) ( V_71 + V_74 ) ,
V_12 + V_74 , V_23 , V_24 ) ;
V_74 += 2 ;
}
}
if ( ( V_72 - V_74 ) & 0x1 ) {
F_25 ( V_5 , ( T_3 * ) ( V_71 + V_74 ) , V_12 + V_74 , V_23 ,
V_24 ) ;
V_74 += 1 ;
}
V_76:
V_44 = V_72 ;
F_15 ( & V_18 -> V_51 ) ;
return V_44 ;
}
static unsigned int F_29 ( struct V_42 * V_18 ,
unsigned int V_77 , unsigned int V_78 , unsigned int V_79 ,
T_7 V_68 )
{
T_2 V_80 , V_81 ;
T_2 V_23 , V_24 ;
int V_25 ;
struct V_4 * V_5 ;
V_5 = V_18 -> V_28 -> V_6 ;
V_25 = V_18 -> V_29 ;
V_81 = V_5 -> V_52 [ V_25 ] . V_20 ;
V_23 = V_5 -> V_52 [ V_25 ] . V_23 ;
V_24 = V_5 -> V_52 [ V_25 ] . V_24 ;
F_14 ( & V_18 -> V_51 ) ;
V_80 = F_23 ( V_5 , V_81 + V_68 , V_23 , V_24 ) ;
if ( ( V_80 && V_77 ) == ( V_78 && V_77 ) ) {
V_80 = V_80 | ( V_77 | V_79 ) ;
V_80 = V_80 & ( ~ V_77 | V_79 ) ;
F_27 ( V_5 , & V_80 , V_81 + V_68 , V_23 , V_24 ) ;
}
F_15 ( & V_18 -> V_51 ) ;
return V_80 ;
}
static int F_30 ( struct V_56 * V_57 , unsigned long long V_53 ,
T_2 V_23 , T_2 V_24 )
{
int V_25 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_57 -> V_28 ;
V_5 = V_3 -> V_6 ;
F_7 ( & V_57 -> V_40 ) ;
for ( V_25 = 0 ; V_25 < V_57 -> V_63 ; V_25 ++ ) {
if ( V_5 -> V_64 [ V_25 ] != NULL ) {
F_9 ( & V_57 -> V_40 ) ;
F_11 ( L_8 ) ;
return - V_82 ;
}
}
switch ( V_23 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
break;
default:
F_9 ( & V_57 -> V_40 ) ;
F_11 ( L_1 ) ;
return - V_39 ;
}
V_5 -> V_53 = V_53 ;
V_5 -> V_54 = V_23 ;
V_5 -> V_55 = V_24 ;
F_9 ( & V_57 -> V_40 ) ;
return 0 ;
}
static int F_31 ( struct V_56 * V_57 ,
unsigned long long * V_53 , T_2 * V_23 , T_2 * V_24 )
{
struct V_4 * V_5 ;
V_5 = V_57 -> V_28 -> V_6 ;
F_7 ( & V_57 -> V_40 ) ;
* V_53 = V_5 -> V_53 ;
* V_23 = V_5 -> V_54 ;
* V_24 = V_5 -> V_55 ;
F_9 ( & V_57 -> V_40 ) ;
return V_5 -> V_62 ;
}
static int F_32 ( struct V_56 * V_57 , int V_83 ,
void (* F_33)( void * ) , void * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_57 -> V_28 ;
V_5 = V_3 -> V_6 ;
F_7 ( & V_57 -> V_40 ) ;
if ( V_5 -> V_55 == 0 ) {
F_9 ( & V_57 -> V_40 ) ;
F_11 ( L_9 ) ;
return - V_39 ;
}
if ( V_5 -> V_64 [ V_83 ] != NULL ) {
F_9 ( & V_57 -> V_40 ) ;
F_11 ( L_10 ) ;
return - V_82 ;
}
V_5 -> V_64 [ V_83 ] = F_33 ;
V_5 -> V_65 [ V_83 ] = V_1 ;
V_5 -> V_62 = 1 ;
F_9 ( & V_57 -> V_40 ) ;
return 0 ;
}
static int F_34 ( struct V_56 * V_57 , int V_83 )
{
T_2 V_80 ;
int V_25 ;
struct V_4 * V_5 ;
V_5 = V_57 -> V_28 -> V_6 ;
F_7 ( & V_57 -> V_40 ) ;
V_5 -> V_64 [ V_83 ] = NULL ;
V_5 -> V_65 [ V_83 ] = NULL ;
V_80 = 0 ;
for ( V_25 = 0 ; V_25 < V_57 -> V_63 ; V_25 ++ ) {
if ( V_5 -> V_64 [ V_25 ] != NULL )
V_80 = 1 ;
}
if ( V_80 == 0 )
V_5 -> V_62 = 0 ;
F_9 ( & V_57 -> V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
return V_84 ;
}
static void * F_36 ( struct V_85 * V_28 , T_6 V_21 ,
T_1 * V_86 )
{
void * V_87 = F_37 ( V_21 , V_88 ) ;
if ( V_87 != NULL )
* V_86 = F_5 ( V_87 ) ;
return V_87 ;
}
static void F_38 ( struct V_85 * V_28 , T_6 V_21 ,
void * V_89 , T_1 V_86 )
{
F_39 ( V_89 ) ;
}
static int F_40 ( struct V_2 * V_3 )
{
T_2 V_90 ;
struct V_4 * V_5 ;
V_5 = V_3 -> V_6 ;
V_5 -> V_91 = F_41 ( V_92 , V_88 ) ;
V_5 -> V_93 = F_5 ( V_5 -> V_91 ) ;
if ( V_5 -> V_91 == NULL )
return - V_94 ;
V_90 = F_35 ( V_3 ) ;
F_42 ( L_11 , V_90 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = V_3 -> V_6 ;
F_39 ( V_5 -> V_91 ) ;
}
static int T_8 F_44 ( void )
{
int V_44 , V_25 ;
struct V_58 * V_59 = NULL , * V_60 ;
struct V_2 * V_3 ;
struct V_4 * V_95 ;
struct V_42 * V_96 ;
struct V_17 * V_97 ;
struct V_56 * V_57 ;
V_98 = F_45 ( L_12 , V_99 ) ;
V_3 = F_41 ( sizeof( struct V_2 ) , V_88 ) ;
if ( V_3 == NULL ) {
V_44 = - V_94 ;
goto V_100;
}
V_95 = F_41 ( sizeof( struct V_4 ) , V_88 ) ;
if ( V_95 == NULL ) {
V_44 = - V_94 ;
goto V_101;
}
V_3 -> V_6 = V_95 ;
V_3 -> V_28 = V_98 ;
V_95 -> V_28 = V_3 ;
F_46 ( & V_95 -> V_15 ) ;
F_46 ( & V_3 -> V_102 ) ;
F_47 ( & V_95 -> V_16 , F_1 ,
( unsigned long ) V_3 ) ;
strcpy ( V_3 -> V_103 , V_104 ) ;
F_48 ( & V_3 -> V_105 ) ;
for ( V_25 = 0 ; V_25 < V_106 ; V_25 ++ ) {
V_96 = F_37 ( sizeof( struct V_42 ) ,
V_88 ) ;
if ( V_96 == NULL ) {
V_44 = - V_94 ;
goto V_107;
}
V_96 -> V_28 = V_3 ;
F_49 ( & V_96 -> V_51 ) ;
V_96 -> V_108 = 0 ;
V_96 -> V_29 = V_25 ;
V_96 -> V_109 = V_30 | V_31 | V_32 |
V_33 ;
V_96 -> V_110 = V_111 | V_112 | V_113 |
V_114 | V_115 | V_116 | V_117 |
V_118 | V_119 | V_120 | V_121 |
V_122 | V_123 ;
V_96 -> V_124 = V_47 | V_48 ;
memset ( & V_96 -> V_125 , 0 ,
sizeof( struct V_126 ) ) ;
V_96 -> V_127 = NULL ;
F_50 ( & V_96 -> V_61 ,
& V_3 -> V_105 ) ;
}
F_48 ( & V_3 -> V_128 ) ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ ) {
V_97 = F_37 ( sizeof( struct V_17 ) ,
V_88 ) ;
if ( V_97 == NULL ) {
V_44 = - V_94 ;
goto V_129;
}
V_97 -> V_28 = V_3 ;
F_46 ( & V_97 -> V_40 ) ;
V_97 -> V_108 = 0 ;
V_97 -> V_29 = V_25 ;
V_97 -> V_109 = V_30 | V_31 | V_32 |
V_33 | V_34 | V_35 | V_36 |
V_37 | V_38 ;
V_97 -> V_110 = V_111 | V_112 | V_113 |
V_114 | V_115 | V_116 | V_117 |
V_118 | V_119 | V_120 | V_121 |
V_122 | V_123 ;
F_50 ( & V_97 -> V_61 ,
& V_3 -> V_128 ) ;
}
F_48 ( & V_3 -> V_130 ) ;
V_57 = F_37 ( sizeof( struct V_56 ) , V_88 ) ;
if ( V_57 == NULL ) {
F_11 ( L_13 ) ;
V_44 = - V_94 ;
goto V_131;
}
V_57 -> V_28 = V_3 ;
F_46 ( & V_57 -> V_40 ) ;
V_57 -> V_108 = 0 ;
V_57 -> V_29 = 1 ;
V_57 -> V_63 = 4 ;
F_50 ( & V_57 -> V_61 , & V_3 -> V_130 ) ;
V_3 -> V_132 = F_12 ;
V_3 -> V_133 = F_10 ;
V_3 -> V_134 = F_17 ;
V_3 -> V_135 = F_13 ;
V_3 -> V_136 = F_24 ;
V_3 -> V_137 = F_28 ;
V_3 -> V_138 = F_29 ;
V_3 -> V_139 = F_3 ;
V_3 -> V_140 = F_6 ;
V_3 -> V_141 = F_30 ;
V_3 -> V_142 = F_31 ;
V_3 -> V_143 = F_32 ;
V_3 -> V_144 = F_34 ;
V_3 -> V_145 = F_35 ;
V_3 -> V_146 = F_36 ;
V_3 -> V_147 = F_38 ;
F_42 ( L_14 ,
( V_84 == 1 ) ? L_15 : L_16 ) ;
F_42 ( L_17 , V_84 ) ;
V_44 = F_40 ( V_3 ) ;
if ( V_44 ) {
F_11 ( L_18 ) ;
goto V_148;
}
V_44 = F_51 ( V_3 ) ;
if ( V_44 != 0 ) {
F_11 ( L_19 ) ;
goto V_149;
}
V_150 = V_3 ;
return 0 ;
V_149:
F_43 ( V_3 ) ;
V_148:
V_131:
F_19 (pos, n, &fake_bridge->lm_resources) {
V_57 = F_20 ( V_59 , struct V_56 , V_61 ) ;
F_52 ( V_59 ) ;
F_39 ( V_57 ) ;
}
V_129:
F_19 (pos, n, &fake_bridge->slave_resources) {
V_97 = F_20 ( V_59 , struct V_17 , V_61 ) ;
F_52 ( V_59 ) ;
F_39 ( V_97 ) ;
}
V_107:
F_19 (pos, n, &fake_bridge->master_resources) {
V_96 = F_20 ( V_59 , struct V_42 ,
V_61 ) ;
F_52 ( V_59 ) ;
F_39 ( V_96 ) ;
}
F_39 ( V_95 ) ;
V_101:
F_39 ( V_3 ) ;
V_100:
return V_44 ;
}
static void T_9 F_53 ( void )
{
struct V_58 * V_59 = NULL ;
struct V_58 * V_151 ;
struct V_42 * V_96 ;
struct V_17 * V_97 ;
int V_25 ;
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = V_150 ;
V_5 = V_3 -> V_6 ;
F_54 ( L_20 ) ;
for ( V_25 = 0 ; V_25 < V_106 ; V_25 ++ )
V_5 -> V_52 [ V_25 ] . V_19 = 0 ;
for ( V_25 = 0 ; V_25 < V_70 ; V_25 ++ )
V_5 -> V_41 [ V_25 ] . V_19 = 0 ;
V_5 -> V_62 = 0 ;
F_55 ( V_3 ) ;
F_43 ( V_3 ) ;
F_19 (pos, tmplist, &fake_bridge->slave_resources) {
V_97 = F_20 ( V_59 , struct V_17 , V_61 ) ;
F_52 ( V_59 ) ;
F_39 ( V_97 ) ;
}
F_19 (pos, tmplist, &fake_bridge->master_resources) {
V_96 = F_20 ( V_59 , struct V_42 ,
V_61 ) ;
F_52 ( V_59 ) ;
F_39 ( V_96 ) ;
}
F_39 ( V_3 -> V_6 ) ;
F_39 ( V_3 ) ;
F_56 ( V_98 ) ;
}
