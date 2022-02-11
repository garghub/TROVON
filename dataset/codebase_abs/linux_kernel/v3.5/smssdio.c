static int F_1 ( void * V_1 , void * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 ;
V_6 = V_1 ;
F_2 ( V_6 -> V_7 ) ;
while ( V_3 >= V_6 -> V_7 -> V_8 ) {
V_4 = F_3 ( V_6 -> V_7 , V_9 ,
V_2 , V_6 -> V_7 -> V_8 ) ;
if ( V_4 )
goto V_10;
V_2 += V_6 -> V_7 -> V_8 ;
V_3 -= V_6 -> V_7 -> V_8 ;
}
if ( V_3 ) {
V_4 = F_3 ( V_6 -> V_7 , V_9 ,
V_2 , V_3 ) ;
}
V_10:
F_4 ( V_6 -> V_7 ) ;
return V_4 ;
}
static void F_5 ( struct V_11 * V_7 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
T_1 V_3 ;
V_6 = F_6 ( V_7 ) ;
( void ) F_7 ( V_7 , V_16 , & V_4 ) ;
if ( V_4 ) {
F_8 ( L_1 ) ;
return;
}
if ( V_6 -> V_17 == NULL ) {
V_13 = F_9 ( V_6 -> V_18 ) ;
if ( ! V_13 ) {
F_8 ( L_2 ) ;
return;
}
V_4 = F_10 ( V_6 -> V_7 ,
V_13 -> V_19 ,
V_9 ,
V_20 ) ;
if ( V_4 ) {
F_8 ( L_3 , V_4 ) ;
return;
}
V_15 = V_13 -> V_19 ;
if ( V_15 -> V_21 & V_22 ) {
V_6 -> V_17 = V_13 ;
return;
}
if ( V_15 -> V_23 > V_6 -> V_7 -> V_8 )
V_3 = V_15 -> V_23 - V_6 -> V_7 -> V_8 ;
else
V_3 = 0 ;
} else {
V_13 = V_6 -> V_17 ;
V_15 = V_13 -> V_19 ;
V_3 = V_15 -> V_23 - sizeof( struct V_14 ) ;
V_6 -> V_17 = NULL ;
}
if ( V_3 ) {
void * V_2 ;
V_2 = V_13 -> V_19 + ( V_15 -> V_23 - V_3 ) ;
V_3 = F_11 ( V_3 , V_20 ) ;
F_12 ( V_6 -> V_7 -> V_8 != V_20 ) ;
V_4 = F_10 ( V_6 -> V_7 ,
V_2 ,
V_9 ,
V_3 ) ;
if ( V_4 && V_4 != - V_24 ) {
F_13 ( V_6 -> V_18 , V_13 ) ;
F_8 ( L_4 , V_4 ) ;
return;
}
if ( V_4 == - V_24 ) {
while ( V_3 ) {
V_4 = F_10 ( V_6 -> V_7 ,
V_2 , V_9 ,
V_6 -> V_7 -> V_8 ) ;
if ( V_4 ) {
F_13 ( V_6 -> V_18 , V_13 ) ;
F_8 ( L_5
L_6 , V_4 ) ;
return;
}
V_2 += V_6 -> V_7 -> V_8 ;
if ( V_3 > V_6 -> V_7 -> V_8 )
V_3 -= V_6 -> V_7 -> V_8 ;
else
V_3 = 0 ;
}
}
}
V_13 -> V_3 = V_15 -> V_23 ;
V_13 -> V_25 = 0 ;
F_14 ( V_6 -> V_18 , V_13 ) ;
}
static int T_2 F_15 ( struct V_11 * V_7 ,
const struct V_26 * V_27 )
{
int V_4 ;
int V_28 ;
struct V_5 * V_6 ;
struct V_29 V_30 ;
V_28 = V_27 -> V_31 ;
V_6 = F_16 ( sizeof( struct V_5 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
V_6 -> V_7 = V_7 ;
memset ( & V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 . V_34 = & V_7 -> V_35 ;
V_30 . V_36 = 0x5000 ;
V_30 . V_37 = 22 ;
V_30 . V_1 = V_6 ;
snprintf ( V_30 . V_38 , sizeof( V_30 . V_38 ) ,
L_7 , F_17 ( V_7 ) ) ;
V_30 . V_39 = F_1 ;
V_30 . V_40 = F_18 ( V_28 ) -> type ;
if ( V_30 . V_40 != V_41 )
V_30 . V_42 |= V_43 ;
else {
V_4 = - V_44 ;
goto free;
}
V_4 = F_19 ( & V_30 , & V_6 -> V_18 ) ;
if ( V_4 < 0 )
goto free;
F_20 ( V_6 -> V_18 , V_28 ) ;
F_2 ( V_7 ) ;
V_4 = F_21 ( V_7 ) ;
if ( V_4 )
goto V_45;
V_4 = F_22 ( V_7 , V_20 ) ;
if ( V_4 )
goto V_46;
V_4 = F_23 ( V_7 , F_5 ) ;
if ( V_4 )
goto V_46;
F_24 ( V_7 , V_6 ) ;
F_4 ( V_7 ) ;
V_4 = F_25 ( V_6 -> V_18 ) ;
if ( V_4 < 0 )
goto V_47;
return 0 ;
V_47:
F_2 ( V_7 ) ;
F_26 ( V_7 ) ;
V_46:
F_27 ( V_7 ) ;
V_45:
F_4 ( V_7 ) ;
F_28 ( V_6 -> V_18 ) ;
free:
F_29 ( V_6 ) ;
return V_4 ;
}
static void F_30 ( struct V_11 * V_7 )
{
struct V_5 * V_6 ;
V_6 = F_6 ( V_7 ) ;
if ( V_6 -> V_17 )
F_13 ( V_6 -> V_18 , V_6 -> V_17 ) ;
F_28 ( V_6 -> V_18 ) ;
F_2 ( V_7 ) ;
F_26 ( V_7 ) ;
F_27 ( V_7 ) ;
F_4 ( V_7 ) ;
F_29 ( V_6 ) ;
}
static int T_3 F_31 ( void )
{
int V_4 = 0 ;
F_32 ( V_48 L_8 ) ;
F_32 ( V_48 L_9 ) ;
V_4 = F_33 ( & V_49 ) ;
return V_4 ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_49 ) ;
}
