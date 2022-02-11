static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 , V_9 -> V_11 . V_12 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_15 > 3 ) {
F_5 ( L_2 , V_17 , V_15 ) ;
return - V_18 ;
}
V_9 -> V_11 . V_12 = ( V_19 ) V_15 ;
return V_14 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 , V_9 -> V_11 . V_20 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_15 > 8 ) {
F_5 ( L_3 , V_17 , V_15 ) ;
return - V_18 ;
}
V_9 -> V_11 . V_20 = ( V_19 ) V_15 ;
return V_14 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 , V_9 -> V_11 . V_21 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_4 ( V_13 , 16 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_15 & 0xFFFF0000 ) {
F_5 ( L_4 , V_17 , V_15 ) ;
return - V_18 ;
}
V_9 -> V_11 . V_21 = ( V_19 ) V_15 ;
return V_14 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_15 ;
V_19 V_12 , V_22 ;
int V_16 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
V_12 = V_23 | F_11 ( V_9 -> V_11 . V_12 ) ;
F_12 ( V_9 -> V_24 , V_25 , V_12 ) ;
V_22 = F_13 ( V_9 -> V_11 ) ;
F_12 ( V_9 -> V_24 , V_26 , V_22 ) ;
F_14 ( 0 , L_5 , V_12 , V_22 ) ;
return V_14 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_13 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
V_19 V_12 , V_22 , V_27 ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_4 ( V_13 , 10 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
V_12 = V_23 | F_11 ( V_9 -> V_11 . V_12 ) ;
F_12 ( V_9 -> V_24 , V_25 , V_12 ) ;
V_22 = F_16 ( V_9 -> V_11 ) ;
F_17 ( L_6
L_7
L_8 ) ;
F_18 ( V_28 , NULL , 1 ) ;
F_12 ( V_9 -> V_24 , V_26 , V_22 ) ;
V_29:
F_19 ( V_9 -> V_24 , V_26 , & V_27 ) ;
if ( V_27 & V_30 ) {
F_20 () ;
goto V_29;
}
F_18 ( V_31 , NULL , 1 ) ;
F_14 ( 0 , L_5 , V_12 , V_22 ) ;
return V_14 ;
}
static T_3 F_21 ( struct V_32 * V_33 ,
struct V_34 * V_35 , int V_36 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
struct V_6 * V_7 = F_23 ( V_2 , struct V_6 , V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_9 -> V_37 < 0x10 )
return 0 ;
return V_35 -> V_38 ;
}
