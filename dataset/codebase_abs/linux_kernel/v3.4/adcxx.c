static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
T_2 V_12 [ 2 ] ;
T_2 V_13 [ 2 ] ;
int V_14 ;
T_3 V_15 ;
if ( F_5 ( & V_11 -> V_16 ) )
return - V_17 ;
if ( V_11 -> V_18 == 1 ) {
V_14 = F_6 ( V_7 , V_13 , sizeof( V_13 ) ) ;
} else {
V_12 [ 0 ] = V_9 -> V_19 << 3 ;
V_14 = F_7 ( V_7 , V_12 , sizeof( V_12 ) ,
V_13 , sizeof( V_13 ) ) ;
}
if ( V_14 < 0 ) {
F_8 ( V_2 , L_1 ,
V_14 ) ;
goto V_20;
}
V_15 = ( V_13 [ 0 ] << 8 ) + V_13 [ 1 ] ;
F_9 ( V_2 , L_2 , V_15 ) ;
V_15 = V_15 * V_11 -> V_21 >> 12 ;
V_14 = sprintf ( V_5 , L_3 , V_15 ) ;
V_20:
F_10 ( & V_11 -> V_16 ) ;
return V_14 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_4 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
T_3 V_21 ;
if ( F_5 ( & V_11 -> V_16 ) )
return - V_17 ;
V_21 = V_11 -> V_21 ;
F_10 ( & V_11 -> V_16 ) ;
return sprintf ( V_5 , L_3 , V_21 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_4 V_22 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
unsigned long V_15 ;
if ( F_14 ( V_5 , 10 , & V_15 ) )
return - V_23 ;
if ( F_5 ( & V_11 -> V_16 ) )
return - V_17 ;
V_11 -> V_21 = V_15 ;
F_10 ( & V_11 -> V_16 ) ;
return V_22 ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_4 ( V_7 ) ;
return sprintf ( V_5 , L_5 , V_11 -> V_18 ) ;
}
static int T_5 F_16 ( struct V_6 * V_7 )
{
int V_18 = F_17 ( V_7 ) -> V_24 ;
struct V_10 * V_11 ;
int V_14 ;
int V_25 ;
V_11 = F_18 ( sizeof *V_11 , V_26 ) ;
if ( ! V_11 )
return - V_27 ;
V_11 -> V_21 = 3300 ;
V_11 -> V_18 = V_18 ;
F_19 ( & V_11 -> V_16 ) ;
F_20 ( & V_11 -> V_16 ) ;
F_21 ( V_7 , V_11 ) ;
for ( V_25 = 0 ; V_25 < 3 + V_11 -> V_18 ; V_25 ++ ) {
V_14 = F_22 ( & V_7 -> V_2 , & V_28 [ V_25 ] . V_29 ) ;
if ( V_14 ) {
F_23 ( & V_7 -> V_2 , L_6 ) ;
goto V_30;
}
}
V_11 -> V_31 = F_24 ( & V_7 -> V_2 ) ;
if ( F_25 ( V_11 -> V_31 ) ) {
F_23 ( & V_7 -> V_2 , L_7 ) ;
V_14 = F_26 ( V_11 -> V_31 ) ;
goto V_30;
}
F_10 ( & V_11 -> V_16 ) ;
return 0 ;
V_30:
for ( V_25 -- ; V_25 >= 0 ; V_25 -- )
F_27 ( & V_7 -> V_2 , & V_28 [ V_25 ] . V_29 ) ;
F_21 ( V_7 , NULL ) ;
F_10 ( & V_11 -> V_16 ) ;
F_28 ( V_11 ) ;
return V_14 ;
}
static int T_6 F_29 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
int V_25 ;
F_20 ( & V_11 -> V_16 ) ;
F_30 ( V_11 -> V_31 ) ;
for ( V_25 = 0 ; V_25 < 3 + V_11 -> V_18 ; V_25 ++ )
F_27 ( & V_7 -> V_2 , & V_28 [ V_25 ] . V_29 ) ;
F_21 ( V_7 , NULL ) ;
F_10 ( & V_11 -> V_16 ) ;
F_28 ( V_11 ) ;
return 0 ;
}
