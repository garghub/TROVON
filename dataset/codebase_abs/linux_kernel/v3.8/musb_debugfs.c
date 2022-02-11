static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
unsigned V_6 ;
F_2 ( V_2 , L_1 ) ;
for ( V_6 = 0 ; V_6 < F_3 ( V_7 ) ; V_6 ++ ) {
switch ( V_7 [ V_6 ] . V_8 ) {
case 8 :
F_2 ( V_2 , L_2 , V_7 [ V_6 ] . V_9 ,
F_4 ( V_4 -> V_10 , V_7 [ V_6 ] . V_11 ) ) ;
break;
case 16 :
F_2 ( V_2 , L_3 , V_7 [ V_6 ] . V_9 ,
F_5 ( V_4 -> V_10 , V_7 [ V_6 ] . V_11 ) ) ;
break;
case 32 :
F_2 ( V_2 , L_4 , V_7 [ V_6 ] . V_9 ,
F_6 ( V_4 -> V_10 , V_7 [ V_6 ] . V_11 ) ) ;
break;
}
}
return 0 ;
}
static int F_7 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_8 ( V_13 , F_1 , V_12 -> V_14 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
unsigned V_15 ;
V_15 = F_4 ( V_4 -> V_10 , V_16 ) ;
if ( V_15 & V_17 )
F_2 ( V_2 , L_5 ) ;
if ( V_15 & V_18 )
F_2 ( V_2 , L_6 ) ;
if ( V_15 & V_19 )
F_2 ( V_2 , L_7 ) ;
if ( V_15 & V_20 )
F_2 ( V_2 , L_8 ) ;
if ( V_15 & V_21 )
F_2 ( V_2 , L_9 ) ;
if ( V_15 & V_22 )
F_2 ( V_2 , L_10 ) ;
if ( V_15 & V_23 )
F_2 ( V_2 , L_11 ) ;
if ( V_15 & V_24 )
F_2 ( V_2 , L_12 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_8 ( V_13 , F_9 , V_12 -> V_14 ) ;
}
static T_1 F_11 ( struct V_13 * V_13 ,
const char T_2 * V_25 , T_3 V_26 , T_4 * V_27 )
{
struct V_1 * V_2 = V_13 -> V_28 ;
struct V_4 * V_4 = V_2 -> V_5 ;
T_5 V_15 = 0 ;
char V_29 [ 18 ] ;
memset ( V_29 , 0x00 , sizeof( V_29 ) ) ;
if ( F_12 ( & V_29 , V_25 , F_13 ( T_3 , sizeof( V_29 ) - 1 , V_26 ) ) )
return - V_30 ;
if ( ! strncmp ( V_29 , L_13 , 9 ) )
V_15 = V_17 ;
if ( ! strncmp ( V_29 , L_14 , 11 ) )
V_15 = V_18 ;
if ( ! strncmp ( V_29 , L_15 , 15 ) )
V_15 = V_19 ;
if ( ! strncmp ( V_29 , L_16 , 15 ) )
V_15 = V_20 ;
if ( ! strncmp ( V_29 , L_17 , 10 ) ) {
V_15 = V_21 ;
F_14 ( V_4 ) ;
}
if ( ! strncmp ( V_29 , L_18 , 6 ) )
V_15 = V_22 ;
if ( ! strncmp ( V_29 , L_19 , 6 ) )
V_15 = V_23 ;
if ( ! strncmp ( V_29 , L_20 , 12 ) )
V_15 = V_24 ;
F_15 ( V_4 -> V_10 , V_16 , V_15 ) ;
return V_26 ;
}
int F_16 ( struct V_4 * V_4 )
{
struct V_31 * V_32 ;
struct V_31 * V_13 ;
int V_33 ;
V_32 = F_17 ( F_18 ( V_4 -> V_34 ) , NULL ) ;
if ( ! V_32 ) {
V_33 = - V_35 ;
goto V_36;
}
V_13 = F_19 ( L_21 , V_37 , V_32 , V_4 ,
& V_38 ) ;
if ( ! V_13 ) {
V_33 = - V_35 ;
goto V_39;
}
V_13 = F_19 ( L_22 , V_37 | V_40 ,
V_32 , V_4 , & V_41 ) ;
if ( ! V_13 ) {
V_33 = - V_35 ;
goto V_39;
}
V_4 -> V_42 = V_32 ;
return 0 ;
V_39:
F_20 ( V_32 ) ;
V_36:
return V_33 ;
}
void F_21 ( struct V_4 * V_4 )
{
F_20 ( V_4 -> V_42 ) ;
}
