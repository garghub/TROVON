static
struct V_1 * F_1 (
struct V_2 * V_2 ,
enum V_3 V_4 , enum V_3 V_5 ,
void * * V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
void * V_10 ;
struct V_1 * V_11 ;
F_3 ( 3 , V_9 , L_1 ,
V_2 , V_4 , V_5 ) ;
V_7 = - V_12 ;
V_11 = F_4 ( V_13 , V_14 ) ;
if ( V_11 == NULL ) {
F_5 ( V_9 , L_2 ) ;
goto V_15;
}
V_10 = F_6 ( V_11 , 0 , V_16 . V_17 ,
& V_16 , 0 , V_18 ) ;
if ( V_10 == NULL ) {
F_5 ( V_9 , L_3 ) ;
goto V_19;
}
* V_6 = V_10 ;
V_7 = F_7 ( V_11 , V_20 , V_5 ) ;
if ( V_7 < 0 ) {
F_5 ( V_9 , L_4 , V_7 ) ;
goto V_19;
}
V_7 = F_7 ( V_11 , V_21 , V_4 ) ;
if ( V_7 < 0 ) {
F_5 ( V_9 , L_5 , V_7 ) ;
goto V_19;
}
V_7 = F_8 ( V_11 , V_22 ,
V_2 -> V_23 -> V_24 ) ;
if ( V_7 < 0 ) {
F_5 ( V_9 , L_6 ) ;
goto V_19;
}
F_9 ( 3 , V_9 , L_7 ,
V_2 , V_4 , V_5 , V_11 ) ;
return V_11 ;
V_19:
F_10 ( V_11 ) ;
V_15:
F_9 ( 3 , V_9 , L_8 ,
V_2 , V_4 , V_5 , V_7 ) ;
return F_11 ( V_7 ) ;
}
static
int F_12 (
struct V_2 * V_2 , struct V_1 * V_11 ,
void * V_6 )
{
int V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( 3 , V_9 , L_9 ,
V_2 , V_11 ) ;
if ( V_11 == NULL ) {
V_7 = - V_12 ;
goto V_25;
}
F_13 ( V_11 , V_6 ) ;
F_14 ( & V_16 , V_11 , 0 , 0 , V_14 ) ;
V_25:
F_9 ( 3 , V_9 , L_10 ,
V_2 , V_11 , V_7 ) ;
return V_7 ;
}
static
void F_15 ( enum V_3 V_5 , enum V_3 V_4 ,
unsigned int V_26 )
{
if ( F_16 ( ( ( 1 << V_4 ) & V_26 ) == 0 ) ) {
F_17 ( V_27 L_11 ,
V_5 , V_4 ) ;
}
}
void F_18 ( struct V_2 * V_2 , enum V_3 V_4 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
enum V_3 V_5 = V_2 -> V_28 ;
struct V_1 * V_29 ;
void * V_6 ;
F_3 ( 3 , V_9 , L_12 ,
V_2 , V_4 , V_5 ) ;
if ( F_16 ( V_4 >= V_30 ) ) {
F_5 ( V_9 , L_13 ,
V_4 ) ;
goto V_25;
}
if ( V_5 == V_4 )
goto V_25;
V_6 = NULL ;
V_29 = F_1 (
V_2 , V_4 , V_5 , & V_6 ) ;
switch ( V_5 ) {
case V_31 :
F_15 ( V_5 , V_4 ,
1 << V_32 ) ;
break;
case V_32 :
F_15 ( V_5 , V_4 ,
1 << V_33
| 1 << V_34
| 1 << V_35 ) ;
break;
case V_33 :
F_15 ( V_5 , V_4 , 1 << V_32 ) ;
break;
case V_34 :
F_15 ( V_5 , V_4 ,
1 << V_33
| 1 << V_35 ) ;
break;
case V_35 :
F_15 ( V_5 , V_4 ,
1 << V_33
| 1 << V_36 ) ;
break;
case V_36 :
F_15 ( V_5 , V_4 ,
1 << V_33
| 1 << V_35
| 1 << V_37
| 1 << V_38
| 1 << V_39 ) ;
break;
case V_37 :
F_15 ( V_5 , V_4 ,
1 << V_33
| 1 << V_35
| 1 << V_36
| 1 << V_38
| 1 << V_39 ) ;
break;
case V_38 :
F_15 ( V_5 , V_4 ,
1 << V_33
| 1 << V_35
| 1 << V_36
| 1 << V_37
| 1 << V_39 ) ;
break;
case V_39 :
F_15 ( V_5 , V_4 ,
1 << V_33
| 1 << V_35
| 1 << V_36 ) ;
F_19 ( V_2 -> V_23 ) ;
F_20 ( V_2 -> V_23 ) ;
break;
case V_30 :
default:
F_5 ( V_9 , L_14 ,
V_2 , V_2 -> V_28 ) ;
F_16 ( 1 ) ;
goto V_25;
}
switch ( V_4 ) {
case V_31 :
F_5 ( V_9 , L_15
L_16 , V_2 , V_2 -> V_28 ) ;
F_16 ( 1 ) ;
break;
case V_32 :
break;
case V_33 :
break;
case V_34 :
break;
case V_35 :
break;
case V_36 :
break;
case V_37 :
break;
case V_38 :
break;
case V_39 :
F_21 ( V_2 -> V_23 ) ;
F_22 ( V_2 -> V_23 ) ;
break;
case V_30 :
default:
F_23 () ;
}
F_24 ( V_2 , V_4 ) ;
if ( ! F_25 ( V_29 ) )
F_12 ( V_2 , V_29 , V_6 ) ;
V_25:
F_9 ( 3 , V_9 , L_17 ,
V_2 , V_4 , V_5 ) ;
}
void F_26 ( struct V_2 * V_2 , enum V_3 V_4 )
{
F_27 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_28 > V_31 )
F_18 ( V_2 , V_4 ) ;
F_28 ( & V_2 -> V_40 ) ;
}
enum V_3 F_29 ( struct V_2 * V_2 )
{
enum V_3 V_28 ;
F_27 ( & V_2 -> V_40 ) ;
V_28 = V_2 -> V_28 ;
F_28 ( & V_2 -> V_40 ) ;
return V_28 ;
}
void F_30 ( struct V_2 * V_2 )
{
F_31 ( & V_2 -> V_41 ) ;
F_24 ( V_2 , V_31 ) ;
F_32 ( & V_2 -> V_40 ) ;
F_32 ( & V_2 -> V_42 ) ;
}
static
T_1 F_33 ( char * V_43 , T_1 V_44 ,
unsigned char * V_45 , T_1 V_46 )
{
unsigned int V_47 , V_48 ;
for ( V_48 = V_47 = 0 ; V_47 < V_46 ; V_47 ++ )
V_48 += F_34 ( V_43 + V_48 , V_44 - V_48 ,
L_18 , V_45 [ V_47 ] ,
V_47 == V_46 - 1 ? '\0' : ':' ) ;
return V_48 ;
}
int F_35 ( struct V_2 * V_2 , struct V_49 * V_23 )
{
int V_7 ;
struct V_8 * V_9 = V_23 -> V_9 . V_50 ;
char V_43 [ 32 ] ;
F_3 ( 3 , V_9 , L_19 , V_2 , V_23 ) ;
V_2 -> V_23 = V_23 ;
V_7 = F_36 ( V_2 ) ;
if ( V_7 < 0 )
goto V_51;
F_27 ( & V_2 -> V_40 ) ;
F_37 ( V_2 ) ;
V_7 = F_38 ( V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( V_9 , L_20 ,
V_7 ) ;
goto V_52;
}
F_24 ( V_2 , V_32 ) ;
F_28 ( & V_2 -> V_40 ) ;
F_33 ( V_43 , sizeof( V_43 ) ,
V_23 -> V_53 , V_23 -> V_46 ) ;
F_5 ( V_9 , L_21 ,
V_23 -> V_54 , V_43 ) ;
F_9 ( 3 , V_9 , L_22 , V_2 , V_23 ) ;
return 0 ;
V_52:
F_39 ( V_2 ) ;
F_28 ( & V_2 -> V_40 ) ;
F_40 ( V_2 ) ;
V_51:
F_9 ( 3 , V_9 , L_23 ,
V_2 , V_23 , V_7 ) ;
return V_7 ;
}
void F_41 ( struct V_2 * V_2 )
{
F_3 ( 3 , NULL , L_24 , V_2 ) ;
F_27 ( & V_2 -> V_40 ) ;
F_18 ( V_2 , V_33 ) ;
F_42 ( V_2 ) ;
F_39 ( V_2 ) ;
F_18 ( V_2 , V_32 ) ;
F_28 ( & V_2 -> V_40 ) ;
F_40 ( V_2 ) ;
F_9 ( 3 , NULL , L_25 , V_2 ) ;
}
static
int T_2 F_43 ( void )
{
int V_7 ;
F_3 ( 4 , NULL , L_26 ) ;
F_44 ( V_55 , V_56 , V_57 ,
L_27 ) ;
snprintf ( V_16 . V_54 , sizeof( V_16 . V_54 ) ,
L_28 ) ;
V_7 = F_45 ( & V_16 ,
V_58 ,
V_59 ) ;
if ( F_46 ( V_7 < 0 ) ) {
F_17 ( V_27 L_29 ,
V_7 ) ;
goto V_60;
}
F_9 ( 4 , NULL , L_30 ) ;
return 0 ;
V_60:
F_9 ( 4 , NULL , L_31 , V_7 ) ;
return V_7 ;
}
static
void T_3 F_47 ( void )
{
F_48 () ;
F_49 ( & V_16 ) ;
}
