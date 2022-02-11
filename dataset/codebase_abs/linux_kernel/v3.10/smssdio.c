static int F_1 ( void * V_1 , void * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 ;
V_6 = V_1 ;
F_2 ( V_6 -> V_7 ) ;
F_3 ( (struct V_8 * ) V_2 ) ;
while ( V_3 >= V_6 -> V_7 -> V_9 ) {
V_4 = F_4 ( V_6 -> V_7 , V_10 ,
V_2 , V_6 -> V_7 -> V_9 ) ;
if ( V_4 )
goto V_11;
V_2 += V_6 -> V_7 -> V_9 ;
V_3 -= V_6 -> V_7 -> V_9 ;
}
if ( V_3 ) {
V_4 = F_4 ( V_6 -> V_7 , V_10 ,
V_2 , V_3 ) ;
}
V_11:
F_5 ( V_6 -> V_7 ) ;
return V_4 ;
}
static void F_6 ( struct V_12 * V_7 )
{
int V_4 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
T_1 V_3 ;
V_6 = F_7 ( V_7 ) ;
( void ) F_8 ( V_7 , V_17 , & V_4 ) ;
if ( V_4 ) {
F_9 ( L_1 ) ;
return;
}
if ( V_6 -> V_18 == NULL ) {
V_14 = F_10 ( V_6 -> V_19 ) ;
if ( ! V_14 ) {
F_9 ( L_2 ) ;
return;
}
V_4 = F_11 ( V_6 -> V_7 ,
V_14 -> V_20 ,
V_10 ,
V_21 ) ;
if ( V_4 ) {
F_9 ( L_3 , V_4 ) ;
return;
}
V_16 = V_14 -> V_20 ;
if ( V_16 -> V_22 & V_23 ) {
V_6 -> V_18 = V_14 ;
return;
}
if ( V_16 -> V_24 > V_6 -> V_7 -> V_9 )
V_3 = V_16 -> V_24 - V_6 -> V_7 -> V_9 ;
else
V_3 = 0 ;
} else {
V_14 = V_6 -> V_18 ;
V_16 = V_14 -> V_20 ;
V_3 = V_16 -> V_24 - sizeof( struct V_15 ) ;
V_6 -> V_18 = NULL ;
}
if ( V_3 ) {
void * V_2 ;
V_2 = V_14 -> V_20 + ( V_16 -> V_24 - V_3 ) ;
V_3 = F_12 ( V_3 , V_21 ) ;
F_13 ( V_6 -> V_7 -> V_9 != V_21 ) ;
V_4 = F_11 ( V_6 -> V_7 ,
V_2 ,
V_10 ,
V_3 ) ;
if ( V_4 && V_4 != - V_25 ) {
F_14 ( V_6 -> V_19 , V_14 ) ;
F_9 ( L_4 , V_4 ) ;
return;
}
if ( V_4 == - V_25 ) {
while ( V_3 ) {
V_4 = F_11 ( V_6 -> V_7 ,
V_2 , V_10 ,
V_6 -> V_7 -> V_9 ) ;
if ( V_4 ) {
F_14 ( V_6 -> V_19 , V_14 ) ;
F_9 ( L_5
L_6 , V_4 ) ;
return;
}
V_2 += V_6 -> V_7 -> V_9 ;
if ( V_3 > V_6 -> V_7 -> V_9 )
V_3 -= V_6 -> V_7 -> V_9 ;
else
V_3 = 0 ;
}
}
}
V_14 -> V_3 = V_16 -> V_24 ;
V_14 -> V_26 = 0 ;
F_15 ( (struct V_8 * ) V_14 -> V_20 ) ;
F_16 ( V_6 -> V_19 , V_14 ) ;
}
static int F_17 ( struct V_12 * V_7 ,
const struct V_27 * V_28 )
{
int V_4 ;
int V_29 ;
struct V_5 * V_6 ;
struct V_30 V_31 ;
V_29 = V_28 -> V_32 ;
V_6 = F_18 ( sizeof( struct V_5 ) , V_33 ) ;
if ( ! V_6 )
return - V_34 ;
V_6 -> V_7 = V_7 ;
memset ( & V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 . V_35 = & V_7 -> V_36 ;
V_31 . V_37 = 0x5000 ;
V_31 . V_38 = 22 ;
V_31 . V_1 = V_6 ;
snprintf ( V_31 . V_39 , sizeof( V_31 . V_39 ) ,
L_7 , F_19 ( V_7 ) ) ;
V_31 . V_40 = F_1 ;
V_31 . V_41 = F_20 ( V_29 ) -> type ;
if ( V_31 . V_41 != V_42 )
V_31 . V_43 |= V_44 ;
else {
V_4 = - V_45 ;
goto free;
}
V_4 = F_21 ( & V_31 , & V_6 -> V_19 ) ;
if ( V_4 < 0 )
goto free;
F_22 ( V_6 -> V_19 , V_29 ) ;
F_2 ( V_7 ) ;
V_4 = F_23 ( V_7 ) ;
if ( V_4 )
goto V_46;
V_4 = F_24 ( V_7 , V_21 ) ;
if ( V_4 )
goto V_47;
V_4 = F_25 ( V_7 , F_6 ) ;
if ( V_4 )
goto V_47;
F_26 ( V_7 , V_6 ) ;
F_5 ( V_7 ) ;
V_4 = F_27 ( V_6 -> V_19 ) ;
if ( V_4 < 0 )
goto V_48;
return 0 ;
V_48:
F_2 ( V_7 ) ;
F_28 ( V_7 ) ;
V_47:
F_29 ( V_7 ) ;
V_46:
F_5 ( V_7 ) ;
F_30 ( V_6 -> V_19 ) ;
free:
F_31 ( V_6 ) ;
return V_4 ;
}
static void F_32 ( struct V_12 * V_7 )
{
struct V_5 * V_6 ;
V_6 = F_7 ( V_7 ) ;
if ( V_6 -> V_18 )
F_14 ( V_6 -> V_19 , V_6 -> V_18 ) ;
F_30 ( V_6 -> V_19 ) ;
F_2 ( V_7 ) ;
F_28 ( V_7 ) ;
F_29 ( V_7 ) ;
F_5 ( V_7 ) ;
F_31 ( V_6 ) ;
}
static int T_2 F_33 ( void )
{
int V_4 = 0 ;
F_34 ( V_49 L_8 ) ;
F_34 ( V_49 L_9 ) ;
V_4 = F_35 ( & V_50 ) ;
return V_4 ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_50 ) ;
}
