static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
char * V_6 = V_5 ;
int V_7 = 0 ;
unsigned long V_8 ;
F_2 ( ! V_9 || ! V_5 ) ;
F_3 ( & V_9 -> V_10 , V_8 ) ;
V_5 += sprintf ( V_5 ,
L_1 ) ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
struct V_12 * V_13 = F_4 ( V_7 ) ;
F_5 ( & V_13 -> V_14 . V_10 ) ;
V_5 += sprintf ( V_5 , L_2 , V_7 , V_13 -> V_14 . V_15 ) ;
if ( V_13 -> V_14 . V_15 == V_16 ) {
V_5 += sprintf ( V_5 , L_3 ,
V_13 -> V_17 , V_13 -> V_18 ) ;
V_5 += sprintf ( V_5 , L_4 , V_13 -> V_14 . V_19 ) ;
V_5 += sprintf ( V_5 , L_5 , F_6 ( & V_13 -> V_20 -> V_2 ) ) ;
} else {
V_5 += sprintf ( V_5 , L_6 ) ;
}
V_5 += sprintf ( V_5 , L_7 ) ;
F_7 ( & V_13 -> V_14 . V_10 ) ;
}
F_8 ( & V_9 -> V_10 , V_8 ) ;
return V_5 - V_6 ;
}
static int F_9 ( T_2 V_21 )
{
struct V_12 * V_13 ;
unsigned long V_8 ;
F_10 ( L_8 ) ;
F_3 ( & V_9 -> V_10 , V_8 ) ;
V_13 = F_4 ( V_21 ) ;
F_5 ( & V_13 -> V_14 . V_10 ) ;
if ( V_13 -> V_14 . V_15 == V_22 ) {
F_11 ( L_9 , V_13 -> V_14 . V_15 ) ;
F_7 ( & V_13 -> V_14 . V_10 ) ;
F_8 ( & V_9 -> V_10 , V_8 ) ;
return - V_23 ;
}
F_7 ( & V_13 -> V_14 . V_10 ) ;
F_8 ( & V_9 -> V_10 , V_8 ) ;
F_12 ( & V_13 -> V_14 , V_24 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_25 , T_3 V_26 )
{
int V_27 ;
T_2 V_21 = 0 ;
if ( sscanf ( V_25 , L_10 , & V_21 ) != 1 )
return - V_23 ;
if ( V_21 >= V_11 ) {
F_14 ( V_2 , L_11 , V_21 ) ;
return - V_23 ;
}
V_27 = F_9 ( V_21 ) ;
if ( V_27 < 0 )
return - V_23 ;
F_10 ( L_12 ) ;
return V_26 ;
}
static int F_15 ( T_2 V_21 , enum V_28 V_17 )
{
if ( V_21 >= V_11 ) {
F_11 ( L_13 , V_21 ) ;
return - V_23 ;
}
switch ( V_17 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
break;
default:
F_11 ( L_14 ,
F_16 ( V_17 ) ) ;
return - V_23 ;
}
return 0 ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_25 , T_3 V_26 )
{
struct V_12 * V_13 ;
struct V_33 * V_33 ;
int V_34 = 0 ;
T_2 V_21 = 0 , V_18 = 0 , V_17 = 0 ;
int V_27 ;
unsigned long V_8 ;
if ( sscanf ( V_25 , L_15 , & V_21 , & V_34 , & V_18 , & V_17 ) != 4 )
return - V_23 ;
F_10 ( L_16 ,
V_21 , V_34 , V_18 , V_17 ) ;
if ( F_15 ( V_21 , V_17 ) < 0 )
return - V_23 ;
V_33 = F_18 ( V_34 , & V_27 ) ;
if ( ! V_33 )
return - V_23 ;
F_3 ( & V_9 -> V_10 , V_8 ) ;
V_13 = F_4 ( V_21 ) ;
F_5 ( & V_13 -> V_14 . V_10 ) ;
if ( V_13 -> V_14 . V_15 != V_22 ) {
F_7 ( & V_13 -> V_14 . V_10 ) ;
F_8 ( & V_9 -> V_10 , V_8 ) ;
F_19 ( V_33 ) ;
F_14 ( V_2 , L_17 , V_21 ) ;
return - V_23 ;
}
F_20 ( V_2 ,
L_18 ,
V_21 , V_34 , V_18 , V_17 , F_16 ( V_17 ) ) ;
V_13 -> V_18 = V_18 ;
V_13 -> V_17 = V_17 ;
V_13 -> V_14 . V_19 = V_33 ;
V_13 -> V_14 . V_15 = V_35 ;
F_7 ( & V_13 -> V_14 . V_10 ) ;
F_8 ( & V_9 -> V_10 , V_8 ) ;
V_13 -> V_14 . V_36 = F_21 ( V_37 , & V_13 -> V_14 , L_19 ) ;
V_13 -> V_14 . V_38 = F_21 ( V_39 , & V_13 -> V_14 , L_20 ) ;
F_22 ( V_21 , V_17 ) ;
return V_26 ;
}
