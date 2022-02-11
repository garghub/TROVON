static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 V_14 = F_2 ( V_2 ) ;
F_3 ( & V_11 -> V_15 ) ;
F_4 ( & V_11 -> V_16 , & V_14 ) ;
F_5 ( & V_11 -> V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_7 * V_8 = V_2 -> V_6 ;
struct V_10 * V_11 = V_8 -> V_12 ;
int V_17 , V_18 ;
if ( V_11 ) {
for ( V_17 = 0 ; V_17 < F_7 ( V_11 -> V_19 ) ; V_17 ++ ) {
struct V_20 * V_19 = V_11 -> V_19 [ V_17 ] ;
if ( ! V_19 )
continue;
for ( V_18 = 0x84 ; V_18 <= 0x1c4 ; V_18 += 4 ) {
T_1 V_21 = F_8 ( V_19 -> V_22 + V_18 ) ;
F_9 ( V_2 , L_1 , V_17 , V_18 , V_21 ) ;
}
}
}
return 0 ;
}
static int F_10 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_11 ( V_24 , F_6 , V_23 -> V_25 ) ;
}
static int F_12 ( struct V_24 * V_24 , const char T_2 * V_26 ,
T_3 V_27 , T_4 * V_28 )
{
struct V_7 * V_8 = V_24 -> V_29 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_20 * V_19 = V_11 -> V_19 [ 0 ] ;
char V_30 [ 32 ] , * V_14 ;
T_1 V_31 , V_32 ;
int V_33 ;
if ( * V_28 != 0 )
return 0 ;
if ( V_27 > sizeof( V_30 ) - 1 )
V_27 = sizeof( V_30 ) - 1 ;
V_33 = F_13 ( V_30 , V_26 , V_27 ) ;
if ( V_33 < 0 )
return V_33 ;
V_30 [ V_27 ] = '\0' ;
V_31 = F_14 ( V_30 , & V_14 , 16 ) ;
if ( ! isspace ( * V_14 ) )
return - V_34 ;
V_32 = F_14 ( V_14 + 1 , NULL , 16 ) ;
if ( V_31 >= 0x84 && V_31 <= 0x1c4 )
F_15 ( V_32 , V_19 -> V_22 + V_31 ) ;
return V_27 ;
}
int F_16 ( struct V_35 * V_9 )
{
struct V_36 * V_37 ;
int V_33 ;
V_33 = F_17 ( V_38 ,
V_39 ,
V_9 -> V_40 , V_9 ) ;
if ( V_33 )
return V_33 ;
V_37 = F_18 ( L_2 , V_41 | V_42 ,
V_9 -> V_40 , V_9 -> V_8 , & V_43 ) ;
if ( ! V_37 )
return - V_44 ;
V_37 = F_18 ( L_3 , V_41 | V_45 ,
V_9 -> V_40 , V_9 -> V_8 , & V_46 ) ;
if ( ! V_37 )
return - V_44 ;
return 0 ;
}
