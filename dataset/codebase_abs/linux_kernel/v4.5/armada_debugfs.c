static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
int V_13 ;
F_2 ( & V_11 -> V_14 ) ;
V_13 = F_3 ( V_2 , & V_11 -> V_15 ) ;
F_4 ( & V_11 -> V_14 ) ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 , void * V_3 )
{
struct V_7 * V_8 = V_2 -> V_6 ;
struct V_10 * V_11 = V_8 -> V_12 ;
int V_16 , V_17 ;
if ( V_11 ) {
for ( V_16 = 0 ; V_16 < F_6 ( V_11 -> V_18 ) ; V_16 ++ ) {
struct V_19 * V_18 = V_11 -> V_18 [ V_16 ] ;
if ( ! V_18 )
continue;
for ( V_17 = 0x84 ; V_17 <= 0x1c4 ; V_17 += 4 ) {
T_1 V_20 = F_7 ( V_18 -> V_21 + V_17 ) ;
F_8 ( V_2 , L_1 , V_16 , V_17 , V_20 ) ;
}
}
}
return 0 ;
}
static int F_9 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
return F_10 ( V_23 , F_5 , V_22 -> V_24 ) ;
}
static int F_11 ( struct V_23 * V_23 , const char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
struct V_7 * V_8 = V_23 -> V_28 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_19 * V_18 = V_11 -> V_18 [ 0 ] ;
char V_29 [ 32 ] , * V_30 ;
T_1 V_31 , V_32 ;
int V_13 ;
if ( * V_27 != 0 )
return 0 ;
if ( V_26 > sizeof( V_29 ) - 1 )
V_26 = sizeof( V_29 ) - 1 ;
V_13 = F_12 ( V_29 , V_25 , V_26 ) ;
if ( V_13 < 0 )
return V_13 ;
V_29 [ V_26 ] = '\0' ;
V_31 = F_13 ( V_29 , & V_30 , 16 ) ;
if ( ! isspace ( * V_30 ) )
return - V_33 ;
V_32 = F_13 ( V_30 + 1 , NULL , 16 ) ;
if ( V_31 >= 0x84 && V_31 <= 0x1c4 )
F_14 ( V_32 , V_18 -> V_21 + V_31 ) ;
return V_26 ;
}
static int F_15 ( struct V_34 * V_9 , struct V_35 * V_36 ,
const void * V_37 )
{
struct V_4 * V_5 ;
V_5 = F_16 ( sizeof( struct V_4 ) , V_38 ) ;
if ( V_5 == NULL ) {
F_17 ( V_36 ) ;
return - V_39 ;
}
V_5 -> V_9 = V_9 ;
V_5 -> V_40 = V_36 ;
V_5 -> V_41 = ( void * ) V_37 ;
F_2 ( & V_9 -> V_42 ) ;
F_18 ( & V_5 -> V_43 , & V_9 -> V_44 ) ;
F_4 ( & V_9 -> V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_35 * V_45 , struct V_34 * V_9 ,
const char * V_46 , T_5 V_47 , const struct V_48 * V_49 )
{
struct V_35 * V_50 ;
V_50 = F_20 ( V_46 , V_47 , V_45 , V_9 -> V_8 , V_49 ) ;
return F_15 ( V_9 , V_50 , V_49 ) ;
}
int F_21 ( struct V_34 * V_9 )
{
int V_13 ;
V_13 = F_22 ( V_51 ,
V_52 ,
V_9 -> V_53 , V_9 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_19 ( V_9 -> V_53 , V_9 ,
L_2 , V_54 | V_55 , & V_56 ) ;
if ( V_13 )
goto V_57;
V_13 = F_19 ( V_9 -> V_53 , V_9 ,
L_3 , V_54 | V_58 , & V_59 ) ;
if ( V_13 )
goto V_60;
return V_13 ;
V_60:
F_23 ( (struct V_61 * ) & V_56 , 1 , V_9 ) ;
V_57:
F_23 ( V_51 , V_52 ,
V_9 ) ;
return V_13 ;
}
void F_24 ( struct V_34 * V_9 )
{
F_23 ( (struct V_61 * ) & V_59 , 1 , V_9 ) ;
F_23 ( (struct V_61 * ) & V_56 , 1 , V_9 ) ;
F_23 ( V_51 , V_52 ,
V_9 ) ;
}
