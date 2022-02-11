static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
char * V_6 = V_5 ;
int V_7 = 0 ;
F_2 ( ! V_8 || ! V_5 ) ;
F_3 ( & V_8 -> V_9 ) ;
V_5 += sprintf ( V_5 , L_1
L_2 ) ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
struct V_11 * V_12 = F_4 ( V_7 ) ;
F_3 ( & V_12 -> V_13 . V_9 ) ;
V_5 += sprintf ( V_5 , L_3 , V_7 , V_12 -> V_13 . V_14 ) ;
if ( V_12 -> V_13 . V_14 == V_15 ) {
V_5 += sprintf ( V_5 , L_4 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
V_5 += sprintf ( V_5 , L_5 , V_12 -> V_13 . V_18 ) ;
V_5 += sprintf ( V_5 , L_6 , F_5 ( & V_12 -> V_19 -> V_2 ) ) ;
} else {
V_5 += sprintf ( V_5 , L_7 ) ;
}
V_5 += sprintf ( V_5 , L_8 ) ;
F_6 ( & V_12 -> V_13 . V_9 ) ;
}
F_6 ( & V_8 -> V_9 ) ;
return V_5 - V_6 ;
}
static int F_7 ( T_2 V_20 )
{
struct V_11 * V_12 ;
F_8 ( L_9 ) ;
F_3 ( & V_8 -> V_9 ) ;
V_12 = F_4 ( V_20 ) ;
F_3 ( & V_12 -> V_13 . V_9 ) ;
if ( V_12 -> V_13 . V_14 == V_21 ) {
F_9 ( L_10 , V_12 -> V_13 . V_14 ) ;
F_6 ( & V_12 -> V_13 . V_9 ) ;
F_6 ( & V_8 -> V_9 ) ;
return - V_22 ;
}
F_6 ( & V_12 -> V_13 . V_9 ) ;
F_6 ( & V_8 -> V_9 ) ;
F_10 ( & V_12 -> V_13 , V_23 ) ;
return 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_24 , T_3 V_25 )
{
int V_26 ;
T_2 V_20 = 0 ;
sscanf ( V_24 , L_11 , & V_20 ) ;
if ( V_20 >= V_10 ) {
F_12 ( V_2 , L_12 , V_20 ) ;
return - V_22 ;
}
V_26 = F_7 ( V_20 ) ;
if ( V_26 < 0 )
return - V_22 ;
F_8 ( L_13 ) ;
return V_25 ;
}
static int F_13 ( T_2 V_20 , enum V_27 V_16 )
{
if ( V_20 >= V_10 ) {
F_9 ( L_14 , V_20 ) ;
return - V_22 ;
}
switch ( V_16 ) {
case V_28 :
case V_29 :
case V_30 :
case V_31 :
break;
default:
F_9 ( L_15 ,
F_14 ( V_16 ) ) ;
return - V_22 ;
}
return 0 ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_24 , T_3 V_25 )
{
struct V_11 * V_12 ;
struct V_32 * V_32 ;
int V_33 = 0 ;
T_2 V_20 = 0 , V_17 = 0 , V_16 = 0 ;
sscanf ( V_24 , L_16 , & V_20 , & V_33 , & V_17 , & V_16 ) ;
F_8 ( L_17 ,
V_20 , V_33 , V_17 , V_16 ) ;
if ( F_13 ( V_20 , V_16 ) < 0 )
return - V_22 ;
V_32 = F_16 ( V_33 ) ;
if ( ! V_32 )
return - V_22 ;
F_3 ( & V_8 -> V_9 ) ;
V_12 = F_4 ( V_20 ) ;
F_3 ( & V_12 -> V_13 . V_9 ) ;
if ( V_12 -> V_13 . V_14 != V_21 ) {
F_6 ( & V_12 -> V_13 . V_9 ) ;
F_6 ( & V_8 -> V_9 ) ;
F_17 ( V_32 -> V_34 ) ;
F_12 ( V_2 , L_18 , V_20 ) ;
return - V_22 ;
}
F_18 ( V_2 , L_19 ,
V_20 , V_33 , V_17 , V_16 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_13 . V_18 = V_32 ;
V_12 -> V_13 . V_14 = V_35 ;
F_6 ( & V_12 -> V_13 . V_9 ) ;
F_6 ( & V_8 -> V_9 ) ;
V_12 -> V_13 . V_36 = F_19 ( V_37 , & V_12 -> V_13 , L_20 ) ;
V_12 -> V_13 . V_38 = F_19 ( V_39 , & V_12 -> V_13 , L_21 ) ;
F_20 ( V_20 , V_16 ) ;
return V_25 ;
}
