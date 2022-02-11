static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_6 -> V_7 ) ;
}
static T_1
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_6 -> V_8 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_6 -> V_9 ) ;
}
static int F_5 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
unsigned long V_14 = V_13 -> V_15 - V_13 -> V_16 ;
struct V_6 * V_2 = V_11 -> V_17 ;
int V_18 ;
V_13 -> V_19 = F_6 ( V_13 -> V_19 ) ;
if ( V_2 -> V_9 < V_20 && V_14 == V_20 )
V_18 = F_7 ( V_13 , V_13 -> V_16 , V_2 -> V_21 >> 12 ,
V_13 -> V_19 ) ;
else if ( V_14 <= V_2 -> V_9 )
V_18 = F_8 ( V_13 , V_13 -> V_16 ,
V_2 -> V_21 >> V_22 ,
V_14 , V_13 -> V_19 ) ;
else
return - V_23 ;
if ( V_18 )
return - V_24 ;
return 0 ;
}
static int F_9 ( struct V_25 * V_25 , struct V_10 * V_11 )
{
struct V_26 * V_26 = V_25 -> V_27 ;
struct V_6 * V_2 = F_10 ( V_26 , struct V_6 , V_28 ) ;
V_11 -> V_17 = V_2 ;
return 0 ;
}
static void F_11 ( void )
{
struct V_6 * V_29 , * V_30 ;
F_12 (cur, n, &bsr_devs, bsr_list) {
if ( V_29 -> V_31 ) {
F_13 ( & V_29 -> V_28 ) ;
F_14 ( V_29 -> V_31 ) ;
}
F_15 ( & V_29 -> V_32 ) ;
F_16 ( V_29 ) ;
}
}
static int F_17 ( struct V_33 * V_34 )
{
int V_35 , V_36 , V_37 ;
const T_2 * V_8 ;
const T_2 * V_7 ;
unsigned V_38 ;
int V_18 = - V_39 ;
V_8 = F_18 ( V_34 , L_3 , & V_35 ) ;
V_7 = F_18 ( V_34 , L_4 , & V_36 ) ;
if ( ! V_8 || ! V_7 ||
( V_35 != V_36 ) ) {
F_19 ( V_40 L_5 ) ;
return V_18 ;
}
V_37 = V_36 / sizeof( T_2 ) ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
struct V_6 * V_29 = F_20 ( sizeof( struct V_6 ) ,
V_41 ) ;
struct V_42 V_43 ;
int V_44 ;
if ( ! V_29 ) {
F_19 ( V_40 L_6 ) ;
V_18 = - V_45 ;
goto V_46;
}
V_44 = F_21 ( V_34 , V_38 , & V_43 ) ;
if ( V_44 < 0 ) {
F_19 ( V_40 L_7 ) ;
F_16 ( V_29 ) ;
continue;
}
V_29 -> V_47 = V_38 + V_48 ;
V_29 -> V_21 = V_43 . V_49 ;
V_29 -> V_9 = F_22 ( & V_43 ) ;
V_29 -> V_7 = V_7 [ V_38 ] ;
V_29 -> V_8 = V_8 [ V_38 ] ;
V_29 -> V_6 = F_23 ( V_50 , V_38 + V_48 ) ;
if ( V_29 -> V_9 > 4096 && V_29 -> V_9 < V_20 )
V_29 -> V_9 = 4096 ;
switch( V_29 -> V_7 ) {
case 8 :
V_29 -> V_51 = V_52 ;
break;
case 16 :
V_29 -> V_51 = V_53 ;
break;
case 64 :
V_29 -> V_51 = V_54 ;
break;
case 128 :
V_29 -> V_51 = V_55 ;
break;
case 4096 :
V_29 -> V_51 = V_56 ;
break;
default:
V_29 -> V_51 = V_57 ;
}
V_29 -> V_58 = V_59 [ V_29 -> V_51 ] ;
snprintf ( V_29 -> V_60 , 32 , L_8 ,
V_29 -> V_7 , V_29 -> V_58 ) ;
F_24 ( & V_29 -> V_28 , & V_61 ) ;
V_44 = F_25 ( & V_29 -> V_28 , V_29 -> V_6 , 1 ) ;
if ( V_44 ) {
F_16 ( V_29 ) ;
goto V_46;
}
V_29 -> V_31 = F_26 ( V_62 , NULL , V_29 -> V_6 ,
V_29 , V_29 -> V_60 ) ;
if ( F_27 ( V_29 -> V_31 ) ) {
F_19 ( V_40 L_9 ,
V_29 -> V_60 ) ;
F_13 ( & V_29 -> V_28 ) ;
F_16 ( V_29 ) ;
goto V_46;
}
V_59 [ V_29 -> V_51 ] = V_29 -> V_58 + 1 ;
F_28 ( & V_29 -> V_32 , & V_63 ) ;
}
V_48 += V_37 ;
return 0 ;
V_46:
F_11 () ;
return V_18 ;
}
static int F_29 ( struct V_33 * V_34 )
{
int V_18 ;
while ( V_34 ) {
V_18 = F_17 ( V_34 ) ;
if ( V_18 ) {
F_30 ( V_34 ) ;
return V_18 ;
}
V_34 = F_31 ( V_34 , NULL , L_10 ) ;
}
return 0 ;
}
static int T_3 F_32 ( void )
{
struct V_33 * V_64 ;
T_4 V_6 ;
int V_18 = - V_39 ;
int V_44 ;
V_64 = F_31 ( NULL , NULL , L_10 ) ;
if ( ! V_64 )
goto V_46;
V_62 = F_33 ( V_65 , L_11 ) ;
if ( F_27 ( V_62 ) ) {
F_19 ( V_40 L_12 ) ;
goto V_66;
}
V_62 -> V_67 = V_68 ;
V_44 = F_34 ( & V_6 , 0 , V_69 , L_11 ) ;
V_50 = F_35 ( V_6 ) ;
if ( V_44 < 0 ) {
F_19 ( V_40 L_13 ) ;
goto V_70;
}
if ( ( V_18 = F_29 ( V_64 ) ) < 0 ) {
V_64 = NULL ;
goto V_71;
}
return 0 ;
V_71:
F_36 ( V_6 , V_69 ) ;
V_70:
F_37 ( V_62 ) ;
V_66:
F_30 ( V_64 ) ;
V_46:
return V_18 ;
}
static void T_5 F_38 ( void )
{
F_11 () ;
if ( V_62 )
F_37 ( V_62 ) ;
if ( V_50 )
F_36 ( F_23 ( V_50 , 0 ) , V_69 ) ;
}
