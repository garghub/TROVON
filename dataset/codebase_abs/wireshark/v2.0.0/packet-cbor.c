static T_1 *
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_1 * V_6 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_7 , V_1 , * V_4 , 1 , V_8 ) ;
* V_4 += 1 ;
return V_6 ;
case 0x19 :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_9 , V_1 , * V_4 , 2 , V_8 ) ;
* V_4 += 2 ;
return V_6 ;
case 0x1a :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_10 , V_1 , * V_4 , 4 , V_8 ) ;
* V_4 += 4 ;
return V_6 ;
case 0x1b :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_11 , V_1 , * V_4 , 8 , V_8 ) ;
* V_4 += 8 ;
return V_6 ;
default:
if ( V_5 <= 0x17 ) {
V_6 = F_2 ( V_3 , V_12 , V_1 , * V_4 , 1 , V_8 ) ;
* V_4 += 1 ;
return V_6 ;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_1 , V_5 ) ;
return NULL ;
}
}
static T_1 *
F_4 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_7 V_14 ;
T_1 * V_6 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_14 = ( T_7 ) - 1 - F_5 ( V_1 , * V_4 ) ;
V_6 = F_6 ( V_3 , V_15 , V_1 , * V_4 , 1 , V_14 ) ;
* V_4 += 1 ;
return V_6 ;
case 0x19 :
* V_4 += 1 ;
V_14 = ( T_7 ) - 1 - F_7 ( V_1 , * V_4 ) ;
V_6 = F_6 ( V_3 , V_15 , V_1 , * V_4 , 2 , V_14 ) ;
* V_4 += 2 ;
return V_6 ;
case 0x1a :
* V_4 += 1 ;
V_14 = ( T_7 ) - 1 - F_8 ( V_1 , * V_4 ) ;
V_6 = F_6 ( V_3 , V_15 , V_1 , * V_4 , 4 , V_14 ) ;
* V_4 += 4 ;
return V_6 ;
case 0x1b :
* V_4 += 1 ;
V_14 = ( T_7 ) - 1 - F_9 ( V_1 , * V_4 ) ;
if ( V_14 > - 1 ) {
F_3 ( V_2 , V_3 , & V_16 ,
L_2 ) ;
}
V_6 = F_6 ( V_3 , V_15 , V_1 , * V_4 , 8 , V_14 ) ;
* V_4 += 8 ;
return V_6 ;
default:
if ( V_5 <= 0x17 ) {
V_14 = - 1 - V_5 ;
V_6 = F_6 ( V_3 , V_15 , V_1 , * V_4 , 1 , V_14 ) ;
* V_4 += 1 ;
return V_6 ;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_3 , V_5 ) ;
return NULL ;
}
}
static T_1 *
F_10 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_8 V_17 ;
T_5 V_18 ;
T_4 * V_19 ;
T_1 * V_6 ;
T_1 * V_20 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_17 = F_5 ( V_1 , * V_4 ) ;
* V_4 += 1 ;
break;
case 0x19 :
* V_4 += 1 ;
V_17 = F_7 ( V_1 , * V_4 ) ;
* V_4 += 2 ;
break;
case 0x1a :
* V_4 += 1 ;
V_17 = F_8 ( V_1 , * V_4 ) ;
* V_4 += 4 ;
break;
case 0x1b :
* V_4 += 1 ;
V_17 = F_9 ( V_1 , * V_4 ) ;
* V_4 += 8 ;
break;
case 0x1f :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_21 , V_1 , * V_4 , 1 , V_22 ) ;
V_19 = F_11 ( V_6 , V_23 ) ;
while ( 1 )
{
V_18 = F_5 ( V_1 , * V_4 ) ;
if ( V_18 == 0xff ) {
* V_4 += 1 ;
F_12 ( V_6 , V_1 , * V_4 ) ;
return V_6 ;
}
if ( ( ( V_18 & 0xe0 ) >> 5 ) != V_24 ) {
F_3 ( V_2 , V_3 , & V_25 ,
L_4 , ( V_18 & 0xe0 ) >> 5 ) ;
return NULL ;
}
V_20 = F_10 ( V_1 , V_2 , V_19 , V_4 , V_18 & 0x1f ) ;
if ( ! V_20 )
return NULL ;
}
F_13 () ;
return V_6 ;
default:
if ( V_5 <= 0x17 ) {
V_17 = V_5 ;
* V_4 += 1 ;
break;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_5 , V_5 ) ;
return NULL ;
}
if ( V_17 > V_26 || * V_4 + ( T_5 ) V_17 < * V_4 ) {
F_3 ( V_2 , V_3 , & V_16 ,
L_6 V_27 L_7 , V_17 ) ;
return NULL ;
}
V_6 = F_2 ( V_3 , V_28 , V_1 , * V_4 , ( T_5 ) V_17 , V_8 | V_22 ) ;
* V_4 += ( T_5 ) V_17 ;
return V_6 ;
}
static T_1 *
F_14 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_8 V_17 = 0 ;
T_5 V_18 ;
T_4 * V_19 ;
T_1 * V_6 ;
T_1 * V_20 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_17 = F_5 ( V_1 , * V_4 ) ;
* V_4 += 1 ;
break;
case 0x19 :
* V_4 += 1 ;
V_17 = F_7 ( V_1 , * V_4 ) ;
* V_4 += 2 ;
break;
case 0x1a :
* V_4 += 1 ;
V_17 = F_8 ( V_1 , * V_4 ) ;
* V_4 += 4 ;
break;
case 0x1b :
* V_4 += 1 ;
V_17 = F_9 ( V_1 , * V_4 ) ;
* V_4 += 8 ;
break;
case 0x1f :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_29 , V_1 , * V_4 , 1 , V_22 ) ;
V_19 = F_11 ( V_6 , V_30 ) ;
while ( 1 )
{
V_18 = F_5 ( V_1 , * V_4 ) ;
if ( V_18 == 0xff ) {
* V_4 += 1 ;
F_12 ( V_6 , V_1 , * V_4 ) ;
return V_6 ;
}
if ( ( ( V_18 & 0xe0 ) >> 5 ) != V_31 ) {
F_3 ( V_2 , V_3 , & V_25 ,
L_8 , ( V_18 & 0xe0 ) >> 5 ) ;
return NULL ;
}
V_20 = F_14 ( V_1 , V_2 , V_19 , V_4 , V_18 & 0x1f ) ;
if ( ! V_20 )
return NULL ;
}
F_13 () ;
return V_6 ;
default:
if ( V_5 <= 0x17 ) {
V_17 = V_5 ;
* V_4 += 1 ;
break;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_9 , V_5 ) ;
return NULL ;
}
if ( V_17 > V_26 || * V_4 + ( T_5 ) V_17 < * V_4 ) {
F_3 ( V_2 , V_3 , & V_16 ,
L_6 V_27 L_10 , V_17 ) ;
return NULL ;
}
V_6 = F_2 ( V_3 , V_32 , V_1 , * V_4 , ( T_5 ) V_17 , V_8 | V_33 ) ;
* V_4 += ( T_5 ) V_17 ;
return V_6 ;
}
static T_1 *
F_15 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_8 V_17 = 0 ;
T_8 V_34 ;
T_5 V_35 = * V_4 ;
T_4 * V_19 ;
T_1 * V_6 ;
T_1 * V_20 ;
T_9 V_36 = 0 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_17 = F_5 ( V_1 , * V_4 ) ;
* V_4 += 1 ;
break;
case 0x19 :
* V_4 += 1 ;
V_17 = F_7 ( V_1 , * V_4 ) ;
* V_4 += 2 ;
break;
case 0x1a :
* V_4 += 1 ;
V_17 = F_8 ( V_1 , * V_4 ) ;
* V_4 += 4 ;
break;
case 0x1b :
* V_4 += 1 ;
V_17 = F_9 ( V_1 , * V_4 ) ;
* V_4 += 8 ;
break;
case 0x1f :
* V_4 += 1 ;
V_17 = V_37 ;
V_36 = 1 ;
break;
default:
if ( V_5 <= 0x17 ) {
V_17 = V_5 ;
* V_4 += 1 ;
break;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_11 , V_5 ) ;
return NULL ;
}
if ( V_36 ) {
V_6 = F_16 ( V_3 , V_38 ,
V_1 , V_35 , - 1 , L_12 , L_13 ) ;
} else {
V_6 = F_16 ( V_3 , V_38 ,
V_1 , V_35 , - 1 , L_12 , L_14 V_39 L_15 , V_17 ) ;
}
V_19 = F_11 ( V_6 , V_40 ) ;
for ( V_34 = 0 ; V_34 < V_17 ; V_34 ++ )
{
if ( V_36 ) {
T_5 V_14 = F_5 ( V_1 , * V_4 ) ;
if ( V_14 == 0xff ) {
* V_4 += 1 ;
break;
}
}
V_20 = F_17 ( V_1 , V_2 , V_19 , V_4 ) ;
if ( ! V_20 )
return NULL ;
}
F_12 ( V_6 , V_1 , * V_4 ) ;
return V_6 ;
}
static T_1 *
F_18 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_8 V_17 = 0 ;
T_8 V_34 ;
T_5 V_35 = * V_4 ;
T_4 * V_19 ;
T_1 * V_6 ;
T_9 V_36 = 0 ;
T_4 * V_41 ;
T_1 * V_42 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_17 = F_5 ( V_1 , * V_4 ) ;
* V_4 += 1 ;
break;
case 0x19 :
* V_4 += 1 ;
V_17 = F_7 ( V_1 , * V_4 ) ;
* V_4 += 2 ;
break;
case 0x1a :
* V_4 += 1 ;
V_17 = F_8 ( V_1 , * V_4 ) ;
* V_4 += 4 ;
break;
case 0x1b :
* V_4 += 1 ;
V_17 = F_9 ( V_1 , * V_4 ) ;
* V_4 += 8 ;
break;
case 0x1f :
* V_4 += 1 ;
V_17 = V_37 ;
V_36 = 1 ;
break;
default:
if ( V_5 <= 0x17 ) {
V_17 = V_5 ;
* V_4 += 1 ;
break;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_16 , V_5 ) ;
return NULL ;
}
if ( V_36 ) {
V_6 = F_16 ( V_3 , V_43 ,
V_1 , V_35 , - 1 , L_17 , L_18 ) ;
} else {
V_6 = F_16 ( V_3 , V_43 ,
V_1 , V_35 , - 1 , L_17 , L_14 V_39 L_19 , V_17 ) ;
}
V_19 = F_11 ( V_6 , V_44 ) ;
for ( V_34 = 0 ; V_34 < V_17 ; V_34 ++ )
{
if ( V_36 ) {
T_5 V_14 = F_5 ( V_1 , * V_4 ) ;
if ( V_14 == 0xff ) {
* V_4 += 1 ;
break;
}
}
V_42 = F_17 ( V_1 , V_2 , V_19 , V_4 ) ;
if ( ! V_42 )
return NULL ;
V_41 = F_11 ( V_42 , V_45 ) ;
V_42 = F_17 ( V_1 , V_2 , V_41 , V_4 ) ;
if ( ! V_42 )
return NULL ;
}
F_12 ( V_6 , V_1 , * V_4 ) ;
return V_6 ;
}
static T_1 *
F_19 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_1 * V_6 ;
T_1 * V_46 ;
T_4 * V_47 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_48 , V_1 , * V_4 , 1 , V_8 ) ;
* V_4 += 1 ;
break;
case 0x19 :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_49 , V_1 , * V_4 , 2 , V_8 ) ;
* V_4 += 2 ;
break;
case 0x1a :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_50 , V_1 , * V_4 , 4 , V_8 ) ;
* V_4 += 4 ;
break;
case 0x1b :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_51 , V_1 , * V_4 , 8 , V_8 ) ;
* V_4 += 8 ;
break;
default:
if ( V_5 <= 0x17 ) {
V_6 = F_2 ( V_3 , V_52 , V_1 , * V_4 , 1 , V_8 ) ;
* V_4 += 1 ;
break;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_20 , V_5 ) ;
return NULL ;
}
V_47 = F_11 ( V_6 , V_53 ) ;
V_46 = F_17 ( V_1 , V_2 , V_47 , V_4 ) ;
if ( ! V_46 )
return NULL ;
return V_6 ;
}
static T_1 * F_20 ( T_2 * V_1 , T_4 * V_54 , T_5 * V_4 , int V_55 ) {
int V_56 , V_57 , V_58 ;
float V_59 ;
T_1 * V_6 ;
V_56 = F_7 ( V_1 , * V_4 ) ;
V_57 = ( V_56 >> 10 ) & 0x1f ;
V_58 = V_56 & 0x3ff ;
if ( V_57 == 0 ) {
V_59 = F_21 ( ( float ) V_58 , - 24 ) ;
V_6 = F_22 ( V_54 , V_55 , V_1 , * V_4 , 2 ,
V_56 & 0x8000 ? - V_59 : V_59 ) ;
} else if ( V_57 != 31 ) {
V_59 = F_21 ( ( float ) ( V_58 + 1024 ) , V_57 - 25 ) ;
V_6 = F_22 ( V_54 , V_55 , V_1 , * V_4 , 2 ,
V_56 & 0x8000 ? - V_59 : V_59 ) ;
} else {
V_6 = F_23 ( V_54 , V_55 , V_1 , * V_4 , 2 ,
0 , L_21 , V_58 == 0 ? L_22 : L_23 ) ;
}
* V_4 += 2 ;
return V_6 ;
}
static T_1 *
F_24 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 , T_6 V_5 )
{
T_1 * V_6 ;
switch ( V_5 ) {
case 0x18 :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_60 , V_1 , * V_4 , 1 , V_8 ) ;
* V_4 += 1 ;
return V_6 ;
case 0x19 :
* V_4 += 1 ;
V_6 = F_20 ( V_1 , V_3 , V_4 , V_61 ) ;
return V_6 ;
case 0x1a :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_62 , V_1 , * V_4 , 4 , V_8 ) ;
* V_4 += 4 ;
return V_6 ;
case 0x1b :
* V_4 += 1 ;
V_6 = F_2 ( V_3 , V_63 , V_1 , * V_4 , 8 , V_8 ) ;
* V_4 += 8 ;
return V_6 ;
default:
if ( V_5 <= 0x17 ) {
V_6 = F_2 ( V_3 , V_64 , V_1 , * V_4 , 1 , V_8 ) ;
* V_4 += 1 ;
return V_6 ;
}
F_3 ( V_2 , V_3 , & V_13 ,
L_24 , V_5 ) ;
return NULL ;
}
}
static T_1 *
F_17 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , T_5 * V_4 )
{
T_6 type ;
T_6 V_65 ;
T_6 V_5 ;
type = F_5 ( V_1 , * V_4 ) ;
V_65 = ( type & 0xe0 ) >> 5 ;
V_5 = ( type & 0x1f ) ;
switch ( V_65 ) {
case V_66 :
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
case V_67 :
return F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
case V_24 :
return F_10 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
case V_31 :
return F_14 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
case V_68 :
return F_15 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
case V_69 :
return F_18 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
case V_70 :
return F_19 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
case V_71 :
return F_24 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
F_13 () ;
return NULL ;
}
static void
F_25 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_72 )
{
T_5 V_4 = 0 ;
T_1 * V_73 ;
T_4 * V_3 ;
V_73 = F_2 ( V_72 , V_74 , V_1 , V_4 , - 1 , V_22 ) ;
V_3 = F_11 ( V_73 , V_75 ) ;
F_17 ( V_1 , V_2 , V_3 , & V_4 ) ;
}
void
F_26 ( void )
{
static T_10 V_76 [] = {
{ & V_12 ,
{ L_25 , L_26 ,
V_77 , V_78 , NULL , 0x1f ,
NULL , V_79 }
} ,
{ & V_7 ,
{ L_25 , L_27 ,
V_77 , V_78 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_9 ,
{ L_25 , L_28 ,
V_80 , V_78 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_10 ,
{ L_25 , L_29 ,
V_81 , V_78 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_11 ,
{ L_25 , L_30 ,
V_82 , V_78 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_15 ,
{ L_31 , L_32 ,
V_83 , V_78 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_28 ,
{ L_33 , L_34 ,
V_84 , V_85 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_21 ,
{ L_35 , L_36 ,
V_86 , V_85 , NULL , 0x0 ,
NULL , V_79 }
} ,
{ & V_32 ,
{ L_37 , L_38 ,
V_87 , V_85 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_29 ,
{ L_39 , L_40 ,
V_86 , V_85 , NULL , 0x0 ,
NULL , V_79 }
} ,
{ & V_38 ,
{ L_12 , L_41 ,
V_87 , V_85 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_43 ,
{ L_17 , L_42 ,
V_87 , V_85 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_52 ,
{ L_43 , L_44 ,
V_77 , V_78 , F_27 ( V_88 ) , 0x1f ,
NULL , V_79 }
} ,
{ & V_48 ,
{ L_43 , L_45 ,
V_77 , V_78 , F_27 ( V_88 ) , 0x00 ,
NULL , V_79 }
} ,
{ & V_49 ,
{ L_43 , L_46 ,
V_80 , V_78 , F_27 ( V_88 ) , 0x00 ,
NULL , V_79 }
} ,
{ & V_50 ,
{ L_43 , L_47 ,
V_81 , V_78 , F_27 ( V_88 ) , 0x00 ,
NULL , V_79 }
} ,
{ & V_51 ,
{ L_43 , L_48 ,
V_82 , V_78 | V_89 , F_28 ( V_90 ) , 0x00 ,
NULL , V_79 }
} ,
{ & V_64 ,
{ L_49 , L_50 ,
V_77 , V_78 , F_27 ( V_91 ) , 0x1f ,
NULL , V_79 }
} ,
{ & V_60 ,
{ L_49 , L_51 ,
V_77 , V_78 , F_27 ( V_91 ) , 0x00 ,
NULL , V_79 }
} ,
{ & V_61 ,
{ L_52 , L_53 ,
V_92 , V_85 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_62 ,
{ L_54 , L_55 ,
V_92 , V_85 , NULL , 0x00 ,
NULL , V_79 }
} ,
{ & V_63 ,
{ L_56 , L_57 ,
V_93 , V_85 , NULL , 0x00 ,
NULL , V_79 }
} ,
} ;
static T_5 * V_94 [] = {
& V_75 ,
& V_23 ,
& V_30 ,
& V_40 ,
& V_44 ,
& V_45 ,
& V_53 ,
} ;
static T_11 V_95 [] = {
{ & V_13 ,
{ L_58 , V_96 , V_97 , L_59 , V_98 } } ,
{ & V_25 ,
{ L_60 , V_96 , V_97 , L_61 , V_98 } } ,
{ & V_16 ,
{ L_62 , V_96 , V_97 , L_63 , V_98 } } ,
} ;
T_12 * V_99 ;
V_74 = F_29 ( L_64 , L_65 , L_66 ) ;
F_30 ( V_74 , V_76 , F_31 ( V_76 ) ) ;
F_32 ( V_94 , F_31 ( V_94 ) ) ;
V_99 = F_33 ( V_74 ) ;
F_34 ( V_99 , V_95 , F_31 ( V_95 ) ) ;
F_35 ( L_66 , F_25 , V_74 ) ;
}
void
F_36 ( void )
{
static T_13 V_100 ;
V_100 = F_37 ( F_25 , V_74 ) ;
F_38 ( L_67 , L_68 , V_100 ) ;
}
