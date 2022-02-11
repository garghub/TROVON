void F_1 ( void )
{
F_2 ( L_1 ) ;
F_3 ( & V_1 . V_2 ) ;
F_4 ( & V_1 . V_3 , 0 ) ;
}
void F_5 ( void )
{
F_2 ( L_2 ) ;
}
void F_6 ( T_1 V_4 , T_1 V_5 , T_2 V_6 , void * V_7 , unsigned V_8 )
{
unsigned long V_9 ;
int V_10 ;
F_7 ( & V_1 . V_2 , V_9 ) ;
V_10 = ( V_1 . V_11 + 1 ) & ( V_12 - 1 ) ;
if ( V_10 != V_1 . V_13 ) {
struct V_14 * V_15 = & V_1 . V_16 [ V_1 . V_11 ] ;
V_15 -> V_17 = V_17 ;
V_15 -> V_4 = V_4 ;
V_15 -> V_5 = V_5 ;
V_15 -> V_6 = V_6 ;
V_15 -> V_7 = ( V_18 ) ( unsigned long ) V_7 ;
V_15 -> V_8 = V_8 ;
V_1 . V_11 = V_10 ;
} else {
V_1 . V_19 ++ ;
}
F_8 ( & V_1 . V_2 , V_9 ) ;
}
static void F_9 ( struct V_20 * V_21 )
{
unsigned long V_9 ;
F_2 ( L_3 ) ;
F_7 ( & V_21 -> V_2 , V_9 ) ;
V_21 -> V_11 = V_21 -> V_13 = 0 ;
V_21 -> V_19 = 0 ;
F_8 ( & V_21 -> V_2 , V_9 ) ;
}
int F_10 ( struct V_22 * V_22 , struct V_23 * V_24 )
{
F_2 ( L_4 ) ;
F_2 ( L_5 , V_24 -> V_25 ) ;
if ( F_11 ( 1 , & V_1 . V_3 ) == 1 ) {
F_9 ( & V_1 ) ;
return F_12 ( V_22 , V_24 ) ;
} else {
F_13 ( & V_1 . V_3 ) ;
return - V_26 ;
}
}
int F_14 ( struct V_22 * V_22 , struct V_23 * V_24 )
{
F_9 ( & V_1 ) ;
F_13 ( & V_1 . V_3 ) ;
V_27 = 0 ;
F_2 ( L_6 ) ;
return 0 ;
}
T_3 F_15 ( struct V_23 * V_24 , char T_4 * V_28 , T_5 V_29 ,
T_6 * V_30 )
{
struct V_20 * V_21 = & V_1 ;
int V_31 = 0 ;
int V_32 = V_29 / sizeof( struct V_14 ) ;
int V_33 ;
int V_34 ;
V_33 = V_21 -> V_11 - V_21 -> V_13 ;
if ( V_33 < 0 )
V_33 += V_12 ;
if ( V_32 > V_33 )
V_32 = V_33 ;
if ( V_32 == 0 )
goto V_35;
V_33 = V_12 - V_21 -> V_13 ;
if ( V_33 > V_32 )
V_33 = V_32 ;
V_34 = V_33 * sizeof( struct V_14 ) ;
if ( F_16 ( V_28 , & V_21 -> V_16 [ V_21 -> V_13 ] , V_34 ) ) {
V_31 = - V_36 ;
goto V_35;
}
if ( V_33 == V_32 )
goto V_37;
V_33 = V_32 - V_33 ;
if ( F_16 ( V_28 + V_34 , V_21 -> V_16 , V_33 * sizeof( struct V_14 ) ) ) {
V_31 = - V_36 ;
goto V_35;
}
V_37:
V_21 -> V_13 = ( V_21 -> V_13 + V_32 ) & ( V_12 - 1 ) ;
V_31 = V_32 * sizeof( struct V_14 ) ;
V_35:
return V_31 ;
}
void F_17 ( void )
{
struct V_38 * V_39 ;
V_39 = F_18 ( L_7 , NULL ) ;
if ( V_39 == NULL ) {
F_2 ( L_8 ) ;
return;
} else {
V_1 . V_40 = V_39 ;
if ( F_19 ( L_9 , V_41 , V_39 , NULL ,
& V_42 ) == NULL )
F_2 ( L_10 ) ;
if ( F_20 ( L_11 , V_41 | V_43 , V_39 ,
& V_27 ) == NULL )
F_2 ( L_12 ) ;
}
}
void F_21 ( void )
{
F_22 ( V_1 . V_40 ) ;
}
