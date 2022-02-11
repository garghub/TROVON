static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( F_2 ( (struct V_4 * ) V_2 -> V_5 ) )
F_3 ( V_2 , L_1 ) ;
else
F_3 ( V_2 , L_2 ) ;
return 0 ;
}
static int F_4 ( struct V_6 * V_6 , struct V_7 * V_2 )
{
return F_5 ( V_2 , F_1 , V_6 -> V_8 ) ;
}
static T_1 F_6 ( struct V_7 * V_2 , const char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
struct V_4 * V_12 = ( (struct V_1 * ) V_2 -> V_13 ) -> V_5 ;
char V_14 [ 32 ] ;
T_3 V_15 = F_7 ( V_10 , sizeof( V_14 ) - 1 ) ;
if ( F_8 ( V_14 , V_9 , V_15 ) )
return - V_16 ;
while ( V_15 > 0 && ( V_14 [ V_15 - 1 ] == ' ' || V_14 [ V_15 - 1 ] == '\n' ) )
V_15 -- ;
V_14 [ V_15 ] = '\0' ;
if ( strcmp ( V_14 , L_3 ) == 0 ) {
F_9 ( V_12 -> V_17 ) ;
F_10 ( V_12 , 1 ) ;
} else if ( strcmp ( V_14 , L_4 ) == 0 ) {
F_10 ( V_12 , 1 ) ;
} else {
return - V_18 ;
}
return V_10 ;
}
static T_1 F_11 ( struct V_7 * V_2 , char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_4 * V_12 = V_2 -> V_13 ;
struct V_22 * V_23 ;
T_5 V_24 [ 3 ] ;
T_1 V_25 = - V_26 ;
if ( V_20 == 0 )
return - V_18 ;
if ( * V_21 > 0x0ff )
return 0 ;
V_24 [ 0 ] = * V_21 & 0xff ;
V_24 [ 1 ] = ( * V_21 >> 8 ) & 0xff ;
V_24 [ 2 ] = V_20 < 20 ? V_20 : 20 ;
if ( * V_21 + V_24 [ 2 ] > 0xff )
V_24 [ 2 ] = 0x100 - * V_21 ;
V_23 = F_12 ( V_12 -> V_17 , V_27 , V_24 ,
sizeof( V_24 ) ) ;
if ( ! V_23 )
return - V_26 ;
if ( V_23 -> V_28 && V_23 -> V_28 -> V_29 == V_30 ) {
V_25 = V_23 -> V_24 [ 2 ] ;
if ( V_25 > V_20 )
V_25 = V_20 ;
if ( F_13 ( V_19 , V_23 -> V_24 + 3 , V_25 ) )
V_25 = - V_16 ;
else
* V_21 += V_25 ;
}
F_14 ( V_23 ) ;
return V_25 ;
}
static T_1 F_15 ( struct V_7 * V_2 , const char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_4 * V_12 = V_2 -> V_13 ;
struct V_22 * V_23 ;
T_1 V_25 = - V_26 ;
T_5 V_24 [ 23 ] ;
if ( V_20 == 0 )
return - V_18 ;
if ( * V_21 > 0x0ff )
return - V_31 ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
V_24 [ 0 ] = * V_21 & 0xff ;
V_24 [ 1 ] = ( * V_21 >> 8 ) & 0xff ;
V_24 [ 2 ] = F_16 ( T_3 , 20 , V_20 ) ;
if ( * V_21 + V_24 [ 2 ] > 0xff )
V_24 [ 2 ] = 0x100 - * V_21 ;
if ( F_8 ( V_24 + 3 , V_19 , F_7 ( ( T_5 ) 20 , V_24 [ 2 ] ) ) )
return - V_16 ;
V_23 = F_12 ( V_12 -> V_17 , V_32 , V_24 ,
sizeof( V_24 ) ) ;
if ( ! V_23 )
return - V_26 ;
if ( V_23 -> V_28 && V_23 -> V_28 -> V_29 == V_30 ) {
if ( memcmp ( V_24 , V_23 -> V_24 , 3 + V_24 [ 2 ] ) == 0 ) {
* V_21 += V_24 [ 2 ] ;
V_25 = V_24 [ 2 ] ;
}
}
F_14 ( V_23 ) ;
return V_25 ;
}
static int F_17 ( struct V_4 * V_12 , T_5 * V_14 , long V_21 )
{
V_14 [ 0 ] = V_21 & 0xff ;
V_14 [ 1 ] = ( V_21 >> 8 ) & 0xff ;
if ( V_12 -> V_33 == 3 )
V_14 [ 2 ] = ( V_21 >> 16 ) & 0xff ;
return V_12 -> V_33 == 2 ? 2 : 3 ;
}
static T_1 F_18 ( struct V_4 * V_12 , int V_34 ,
char T_2 * V_19 , T_3 V_20 , T_4 * V_21 )
{
struct V_22 * V_23 ;
T_5 V_24 [ 4 ] ;
T_1 V_25 = 0 ;
int V_35 , V_36 = - V_26 ;
while ( V_20 > 0 ) {
V_36 = - V_26 ;
V_35 = F_17 ( V_12 , V_24 , * V_21 ) ;
V_24 [ V_35 ] = V_20 > 32 ? 32 : V_20 ;
V_23 = F_12 ( V_12 -> V_17 , V_34 , V_24 , V_35 + 1 ) ;
if ( ! V_23 || ! V_23 -> V_28 )
goto V_37;
if ( V_23 -> V_28 -> V_29 == V_38 ||
V_23 -> V_28 -> V_29 == V_39 ) {
if ( memcmp ( V_24 , V_23 -> V_24 , V_35 + 1 ) != 0 )
goto V_37;
if ( F_13 ( V_19 + V_25 , V_23 -> V_24 + V_35 + 1 , V_24 [ V_35 ] ) ) {
V_36 = - V_16 ;
goto V_37;
}
* V_21 += V_24 [ V_35 ] ;
V_20 -= V_24 [ V_35 ] ;
V_25 += V_24 [ V_35 ] ;
V_36 = 0 ;
}
V_37:
F_14 ( V_23 ) ;
if ( V_36 )
return V_25 > 0 ? V_25 : V_36 ;
}
return V_25 ;
}
static T_1 F_19 ( struct V_7 * V_2 , char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_4 * V_12 = V_2 -> V_13 ;
if ( V_20 == 0 )
return - V_18 ;
if ( * V_21 > 0x05fff )
return 0 ;
if ( * V_21 + V_20 > 0x05fff )
V_20 = 0x06000 - * V_21 ;
if ( V_12 -> V_40 & V_41 )
return F_18 ( V_12 , V_39 , V_19 , V_20 , V_21 ) ;
else
return F_18 ( V_12 , V_42 , V_19 , V_20 , V_21 ) ;
}
static T_1 F_20 ( struct V_4 * V_12 , int V_34 ,
T_4 * V_21 )
{
struct V_22 * V_23 ;
T_5 V_24 [ 3 ] ;
int V_35 ;
T_1 V_25 = - V_26 ;
if ( * V_21 & 0x3f )
return - V_18 ;
V_35 = F_17 ( V_12 , V_24 , * V_21 ) ;
V_23 = F_12 ( V_12 -> V_17 , V_34 , V_24 , V_35 ) ;
if ( ! V_23 || ! V_23 -> V_28 )
goto V_37;
if ( V_23 -> V_28 -> V_29 == V_38 ||
V_23 -> V_28 -> V_29 == V_43 ) {
if ( memcmp ( V_24 , V_23 -> V_24 , V_35 ) != 0 )
goto V_37;
V_25 = 0 ;
}
V_37:
F_14 ( V_23 ) ;
return V_25 ;
}
static T_1 F_21 ( struct V_4 * V_12 , int V_34 ,
const char T_2 * V_19 , T_3 V_20 , T_4 * V_21 )
{
struct V_22 * V_23 ;
T_5 V_24 [ 36 ] ;
T_1 V_25 = 0 ;
int V_35 , V_36 = - V_26 ;
while ( V_20 > 0 ) {
V_36 = - V_26 ;
V_35 = F_17 ( V_12 , V_24 , * V_21 ) ;
V_24 [ V_35 ] = V_20 > 32 ? 32 : V_20 ;
if ( F_8 ( V_24 + V_35 + 1 , V_19 , V_24 [ V_35 ] ) ) {
V_36 = - V_16 ;
break;
}
V_23 = F_12 ( V_12 -> V_17 , V_34 , V_24 ,
V_35 + 1 + V_24 [ V_35 ] ) ;
if ( ! V_23 || ! V_23 -> V_28 )
goto V_37;
if ( V_23 -> V_28 -> V_29 == V_38 ||
V_23 -> V_28 -> V_29 == V_44 ) {
if ( memcmp ( V_24 , V_23 -> V_24 , V_35 + 1 + V_24 [ V_35 ] ) != 0 )
goto V_37;
* V_21 += V_24 [ V_35 ] ;
V_20 -= V_24 [ V_35 ] ;
V_25 += V_24 [ V_35 ] ;
V_36 = 0 ;
}
V_37:
F_14 ( V_23 ) ;
if ( V_36 )
break;
}
return V_25 > 0 ? V_25 : V_36 ;
}
static T_1 F_22 ( struct V_7 * V_2 , const char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_4 * V_12 = V_2 -> V_13 ;
T_1 V_36 , V_25 = 0 ;
int V_45 , V_46 ;
if ( V_20 == 0 )
return - V_18 ;
if ( * V_21 > 0x5fff )
return - V_31 ;
if ( V_20 & 0x3f )
return - V_18 ;
if ( * V_21 & 0x3f )
return - V_18 ;
if ( V_12 -> V_40 & V_41 ) {
V_45 = V_43 ;
V_46 = V_44 ;
} else {
V_45 = V_47 ;
V_46 = V_48 ;
}
F_23 ( & V_12 -> V_49 ) ;
while ( V_20 > 0 ) {
V_36 = F_20 ( V_12 , V_45 , V_21 ) ;
if ( V_36 )
break;
V_36 = F_21 ( V_12 , V_46 , V_19 , 64 , V_21 ) ;
if ( V_36 < 0 )
break;
V_25 += V_36 ;
* V_21 += V_36 ;
V_20 -= V_36 ;
if ( V_36 != 64 )
break;
}
F_24 ( & V_12 -> V_49 ) ;
return V_25 > 0 ? V_25 : V_36 ;
}
static void F_25 ( char * V_50 , T_3 V_51 , const T_5 * V_12 ,
const T_3 V_52 )
{
int V_53 , V_54 ;
for ( V_53 = V_54 = 0 ; V_53 < V_52 && V_54 + 4 < V_51 ; V_53 ++ ) {
V_50 [ V_54 ++ ] = V_55 [ ( V_12 [ V_53 ] >> 4 ) & 0x0f ] ;
V_50 [ V_54 ++ ] = V_55 [ V_12 [ V_53 ] & 0x0f ] ;
V_50 [ V_54 ++ ] = ' ' ;
}
V_50 [ V_54 ] = '\0' ;
if ( V_54 > 0 )
V_50 [ V_54 - 1 ] = '\n' ;
if ( V_53 < V_52 && V_54 > 2 )
V_50 [ V_54 - 2 ] = V_50 [ V_54 - 3 ] = '.' ;
}
void F_26 ( struct V_4 * V_12 ,
struct V_56 * V_17 , struct V_57 * V_58 )
{
T_5 * V_24 ;
int V_59 = ( V_58 -> V_60 >> 3 ) + 1 ;
char * V_61 ;
#define F_27 256
if ( F_28 ( & V_17 -> V_62 ) )
return;
V_61 = F_29 ( F_27 , V_63 ) ;
if ( ! V_61 )
return;
V_24 = F_30 ( V_58 , V_63 ) ;
if ( ! V_24 ) {
F_14 ( V_61 ) ;
return;
}
snprintf ( V_61 , F_27 , L_5 ,
V_58 -> V_29 , V_59 ) ;
F_31 ( V_17 , V_61 ) ;
V_24 [ 0 ] = V_58 -> V_29 ;
F_32 ( V_58 , V_24 ) ;
F_25 ( V_61 , F_27 , V_24 , V_59 ) ;
F_31 ( V_17 , V_61 ) ;
switch ( V_58 -> V_29 ) {
case V_64 :
snprintf ( V_61 , F_27 , L_6 ,
L_7 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_8 , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_65 :
snprintf ( V_61 , F_27 , L_6 ,
L_9 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_10 , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_66 :
snprintf ( V_61 , F_27 , L_6 ,
L_11 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_12 , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_67 :
snprintf ( V_61 , F_27 , L_6 ,
L_13 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_14 ,
V_24 [ 2 ] , V_24 [ 1 ] , V_24 [ 2 ] << 8 | V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_68 :
snprintf ( V_61 , F_27 , L_6 ,
L_15 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_69 :
snprintf ( V_61 , F_27 , L_6 ,
L_15 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_70 :
snprintf ( V_61 , F_27 , L_6 ,
L_15 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_27 :
snprintf ( V_61 , F_27 , L_6 ,
L_16 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_17 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 3 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_32 :
snprintf ( V_61 , F_27 , L_6 ,
L_19 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_17 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 3 ] ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 3 ] == 0 ) {
snprintf ( V_61 , F_27 , L_20 ) ;
} else if ( V_24 [ 3 ] + 4 <= V_59 ) {
snprintf ( V_61 , F_27 , L_21 ) ;
F_31 ( V_17 , V_61 ) ;
F_25 ( V_61 , F_27 , V_24 + 4 , V_24 [ 3 ] ) ;
} else {
snprintf ( V_61 , F_27 , L_22 ) ;
}
F_31 ( V_17 , V_61 ) ;
break;
case V_47 :
case V_43 :
snprintf ( V_61 , F_27 , L_6 ,
L_23 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
switch ( V_12 -> V_33 ) {
case 2 :
snprintf ( V_61 , F_27 , L_24 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
break;
case 3 :
snprintf ( V_61 , F_27 , L_25 ,
V_24 [ 3 ] , V_24 [ 2 ] , V_24 [ 1 ] ) ;
break;
default:
snprintf ( V_61 , F_27 , L_26 ) ;
}
F_31 ( V_17 , V_61 ) ;
break;
case V_42 :
case V_39 :
snprintf ( V_61 , F_27 , L_6 ,
L_27 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
switch ( V_12 -> V_33 ) {
case 2 :
snprintf ( V_61 , F_27 , L_17 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 3 ] ) ;
break;
case 3 :
snprintf ( V_61 , F_27 , L_28 ,
V_24 [ 3 ] , V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 4 ] ) ;
break;
default:
snprintf ( V_61 , F_27 , L_26 ) ;
}
F_31 ( V_17 , V_61 ) ;
break;
case V_48 :
case V_44 :
snprintf ( V_61 , F_27 , L_6 ,
L_29 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
switch ( V_12 -> V_33 ) {
case 2 :
snprintf ( V_61 , F_27 , L_17 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 3 ] ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 3 ] == 0 ) {
snprintf ( V_61 , F_27 , L_20 ) ;
} else if ( V_24 [ 3 ] + 4 <= V_59 ) {
snprintf ( V_61 , F_27 , L_21 ) ;
F_31 ( V_17 , V_61 ) ;
F_25 ( V_61 , F_27 , V_24 + 4 , V_24 [ 3 ] ) ;
} else {
snprintf ( V_61 , F_27 , L_22 ) ;
}
break;
case 3 :
snprintf ( V_61 , F_27 , L_28 ,
V_24 [ 3 ] , V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 4 ] ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 4 ] == 0 ) {
snprintf ( V_61 , F_27 , L_20 ) ;
} else if ( V_24 [ 4 ] + 5 <= V_59 ) {
snprintf ( V_61 , F_27 , L_21 ) ;
F_31 ( V_17 , V_61 ) ;
F_25 ( V_61 , F_27 , V_24 + 5 , V_24 [ 4 ] ) ;
} else {
snprintf ( V_61 , F_27 , L_22 ) ;
}
break;
default:
snprintf ( V_61 , F_27 , L_26 ) ;
}
F_31 ( V_17 , V_61 ) ;
break;
case V_71 :
break;
case V_72 :
snprintf ( V_61 , F_27 , L_6 ,
L_30 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_31 ,
V_24 [ 1 ] | ( V_24 [ 2 ] << 8 ) ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_73 :
snprintf ( V_61 , F_27 , L_6 ,
L_32 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_74 :
snprintf ( V_61 , F_27 , L_6 ,
L_33 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_75 :
snprintf ( V_61 , F_27 , L_6 ,
L_34 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_76 :
snprintf ( V_61 , F_27 , L_6 ,
L_35 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_77 :
snprintf ( V_61 , F_27 , L_6 ,
L_32 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_31 ,
V_24 [ 1 ] | ( V_24 [ 2 ] << 8 ) ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
default:
snprintf ( V_61 , F_27 , L_6 ,
L_36 , V_58 -> V_29 , V_59 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
}
F_33 ( & V_17 -> V_78 ) ;
F_14 ( V_24 ) ;
F_14 ( V_61 ) ;
}
void F_34 ( struct V_4 * V_12 ,
struct V_56 * V_17 , struct V_57 * V_58 ,
T_5 * V_24 , int V_60 )
{
char * V_61 ;
#define F_27 256
if ( F_28 ( & V_17 -> V_62 ) )
return;
V_61 = F_29 ( F_27 , V_63 ) ;
if ( ! V_61 )
return;
switch ( V_58 -> V_29 ) {
case V_79 :
snprintf ( V_61 , F_27 , L_37 ,
L_38 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 2 ] < F_35 ( V_80 ) )
snprintf ( V_61 , F_27 , L_39 ,
V_24 [ 2 ] , V_80 [ V_24 [ 2 ] ] , V_24 [ 1 ] ) ;
else
snprintf ( V_61 , F_27 , L_40 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_81 :
snprintf ( V_61 , F_27 , L_37 ,
L_41 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 1 ] == 0 )
snprintf ( V_61 , F_27 , L_42 ) ;
else if ( V_24 [ 2 ] == 0 )
snprintf ( V_61 , F_27 , L_43 ,
V_24 [ 1 ] , V_24 [ 1 ] ) ;
else
snprintf ( V_61 , F_27 , L_44 ,
V_24 [ 1 ] , V_24 [ 1 ] , V_24 [ 2 ] , V_24 [ 2 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_82 :
snprintf ( V_61 , F_27 , L_37 ,
L_45 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 1 ] == 0 ) {
snprintf ( V_61 , F_27 , L_46 ) ;
F_31 ( V_17 , V_61 ) ;
} else if ( V_24 [ 1 ] + 1 <= V_60 ) {
snprintf ( V_61 , F_27 , L_47 ,
V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
F_25 ( V_61 , F_27 , V_24 + 2 , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
} else {
snprintf ( V_61 , F_27 , L_48 ,
V_24 [ 1 ] - 1 ) ;
F_31 ( V_17 , V_61 ) ;
}
break;
case V_30 :
snprintf ( V_61 , F_27 , L_37 ,
L_49 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_17 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 3 ] ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 3 ] == 0 ) {
snprintf ( V_61 , F_27 , L_20 ) ;
F_31 ( V_17 , V_61 ) ;
} else if ( V_24 [ 3 ] + 4 <= V_60 ) {
snprintf ( V_61 , F_27 , L_21 ) ;
F_31 ( V_17 , V_61 ) ;
F_25 ( V_61 , F_27 , V_24 + 4 , V_24 [ 3 ] ) ;
F_31 ( V_17 , V_61 ) ;
} else {
snprintf ( V_61 , F_27 , L_22 ) ;
F_31 ( V_17 , V_61 ) ;
}
break;
case V_38 :
snprintf ( V_61 , F_27 , L_37 ,
L_50 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
switch ( V_12 -> V_33 ) {
case 2 :
snprintf ( V_61 , F_27 , L_17 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 3 ] ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 3 ] == 0 ) {
snprintf ( V_61 , F_27 , L_20 ) ;
} else if ( V_24 [ 3 ] + 4 <= V_60 ) {
snprintf ( V_61 , F_27 , L_21 ) ;
F_31 ( V_17 , V_61 ) ;
F_25 ( V_61 , F_27 , V_24 + 4 , V_24 [ 3 ] ) ;
} else {
snprintf ( V_61 , F_27 , L_22 ) ;
}
break;
case 3 :
snprintf ( V_61 , F_27 , L_28 ,
V_24 [ 3 ] , V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_18 , V_24 [ 4 ] ) ;
F_31 ( V_17 , V_61 ) ;
if ( V_24 [ 4 ] == 0 ) {
snprintf ( V_61 , F_27 , L_20 ) ;
} else if ( V_24 [ 4 ] + 5 <= V_60 ) {
snprintf ( V_61 , F_27 , L_21 ) ;
F_31 ( V_17 , V_61 ) ;
F_25 ( V_61 , F_27 , V_24 + 5 , V_24 [ 4 ] ) ;
} else {
snprintf ( V_61 , F_27 , L_22 ) ;
}
break;
default:
snprintf ( V_61 , F_27 , L_26 ) ;
}
F_31 ( V_17 , V_61 ) ;
break;
case V_73 :
snprintf ( V_61 , F_27 , L_37 ,
L_32 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_51 ,
V_24 [ 2 ] , V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_43 :
snprintf ( V_61 , F_27 , L_37 ,
L_52 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_39 :
snprintf ( V_61 , F_27 , L_37 ,
L_53 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_44 :
snprintf ( V_61 , F_27 , L_37 ,
L_54 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_74 :
snprintf ( V_61 , F_27 , L_37 ,
L_33 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_55 ,
V_24 [ 1 ] , V_24 [ 2 ] , V_24 [ 3 ] , V_24 [ 4 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_56 ,
V_24 [ 5 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_75 :
snprintf ( V_61 , F_27 , L_37 ,
L_34 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_57 ,
( V_24 [ 2 ] << 8 ) | V_24 [ 1 ] ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_58 ,
( V_24 [ 4 ] << 8 ) | V_24 [ 3 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
case V_76 :
snprintf ( V_61 , F_27 , L_37 ,
L_35 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
snprintf ( V_61 , F_27 , L_51 ,
V_24 [ 1 ] , V_24 [ 2 ] ) ;
F_31 ( V_17 , V_61 ) ;
break;
default:
snprintf ( V_61 , F_27 , L_37 ,
L_36 , V_58 -> V_29 , V_60 - 1 ) ;
F_31 ( V_17 , V_61 ) ;
break;
}
F_33 ( & V_17 -> V_78 ) ;
F_14 ( V_61 ) ;
}
void F_36 ( struct V_4 * V_12 ,
struct V_57 * V_83 , struct V_57 * V_84 ,
struct V_57 * V_85 , struct V_57 * V_86 ,
struct V_57 * V_87 )
{
struct V_56 * V_17 = V_12 -> V_17 ;
F_37 ( & V_12 -> V_49 ) ;
if ( V_87 )
V_12 -> V_88 = F_38 ( L_59 , 0600 ,
V_17 -> V_89 , V_12 , & V_90 ) ;
if ( V_83 || V_84 )
V_12 -> V_91 = F_38 ( L_60 ,
( V_84 ? V_92 : 0 ) | ( V_83 ? V_93 : 0 ) ,
V_17 -> V_89 , V_12 , & V_94 ) ;
if ( V_85 && V_85 -> V_95 == 1 && V_85 -> V_96 [ 0 ] -> V_97 == 8 )
V_12 -> V_33 = V_85 -> V_96 [ 0 ] -> V_98 - 1 ;
else
V_12 -> V_33 = - 1 ;
if ( V_12 -> V_33 == 2 || V_12 -> V_33 == 3 ) {
V_12 -> V_99 = F_38 ( L_61 ,
( V_86 ? V_92 : 0 ) | ( V_85 ? V_93 : 0 ) ,
V_17 -> V_89 , V_12 , & V_100 ) ;
} else if ( V_85 || V_86 )
F_39 ( V_17 , L_62 ) ;
}
void F_40 ( struct V_4 * V_12 )
{
struct V_101 * V_102 ;
V_102 = V_12 -> V_88 ;
V_12 -> V_88 = NULL ;
F_41 ( V_102 ) ;
V_102 = V_12 -> V_91 ;
V_12 -> V_91 = NULL ;
F_41 ( V_102 ) ;
V_102 = V_12 -> V_99 ;
V_12 -> V_99 = NULL ;
F_41 ( V_102 ) ;
F_42 ( & V_12 -> V_49 ) ;
}
