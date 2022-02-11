struct V_1 * F_1 ( T_1 V_2 , T_2 V_3 )
{
T_3 V_4 = ( ( T_3 ) V_2 << 32 ) | V_3 ;
struct V_1 * V_5 ;
V_5 = F_2 ( & V_6 , & V_4 , V_7 ) ;
if ( V_5 && ! F_3 ( F_4 ( V_5 ) , V_8 ) )
F_5 ( V_5 ) ;
else
V_5 = NULL ;
F_6 ( L_1 , V_5 , & V_2 ,
F_7 ( V_3 ) ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_5 , T_1 V_2 , T_2 * V_3 )
{
int V_9 = - V_10 ;
T_4 V_11 , V_12 ;
T_3 V_4 ;
if ( * V_3 != 0 ) {
V_11 = F_9 ( * V_3 ) ;
if ( V_11 == V_13 )
return - V_14 ;
V_12 = V_11 ;
} else {
V_11 = F_10 ( T_4 , F_11 () , 2 ) ;
V_12 = V_11 - 1 ;
}
do {
if ( V_11 == 0 )
V_11 ++ ;
if ( V_11 == V_13 )
continue;
V_4 = ( ( T_3 ) V_2 << 32 ) | F_12 ( V_11 ) ;
if ( F_2 ( & V_6 , & V_4 , V_7 ) )
continue;
V_5 -> V_15 = V_4 ;
V_5 -> V_16 = V_2 ;
F_13 ( & V_5 -> V_17 ,
sizeof( V_5 -> V_17 ) ) ;
V_5 -> V_18 = F_12 ( V_11 ) ;
V_5 -> V_19 . V_20 = NULL ;
F_5 ( V_5 ) ;
if ( ! F_14 ( & V_6 ,
& V_5 -> V_19 , V_7 ) ) {
* V_3 = V_5 -> V_18 ;
V_9 = 0 ;
F_6 ( L_2 ,
V_5 , & V_2 , ( int ) F_7 ( * V_3 ) ) ;
break;
} else {
F_15 ( V_5 ) ;
V_9 = - V_21 ;
break;
}
} while ( V_11 ++ != V_12 );
return V_9 ;
}
void F_16 ( struct V_1 * V_5 )
{
if ( ! V_5 -> V_16 )
return;
F_6 ( L_3 ,
V_5 , & V_5 -> V_16 ,
F_7 ( V_5 -> V_18 ) ) ;
F_17 ( & V_6 , & V_5 -> V_19 , V_7 ) ;
F_15 ( V_5 ) ;
V_5 -> V_16 = 0 ;
}
int F_18 ( struct V_22 * V_23 , struct V_24 * V_25 , int V_26 )
{
struct V_23 * V_27 = V_23 -> V_27 ;
struct V_28 * sin = (struct V_28 * ) V_25 ;
struct V_1 * V_5 = F_19 ( V_27 ) ;
struct V_29 * V_30 ;
int V_9 = 0 ;
F_20 ( V_27 ) ;
if ( V_26 != sizeof( struct V_28 ) ||
sin -> V_31 != V_32 ||
V_5 -> V_16 ||
sin -> V_33 . V_34 == F_21 ( V_35 ) ) {
V_9 = - V_14 ;
goto V_36;
}
V_9 = F_8 ( V_5 , sin -> V_33 . V_34 , & sin -> V_37 ) ;
if ( V_9 )
goto V_36;
if ( V_5 -> V_38 ) {
V_30 = V_5 -> V_38 ;
if ( V_30 -> V_39 ( F_22 ( V_23 -> V_27 ) ,
sin -> V_33 . V_34 ) != 0 ) {
V_9 = - V_40 ;
F_16 ( V_5 ) ;
} else {
V_9 = 0 ;
}
goto V_36;
}
V_30 = F_23 ( F_22 ( V_23 -> V_27 ) ,
sin -> V_33 . V_34 ) ;
if ( ! V_30 ) {
V_9 = - V_41 ;
F_16 ( V_5 ) ;
F_24 ( L_4 ,
V_42 , & sin -> V_33 . V_34 ) ;
goto V_36;
}
V_5 -> V_38 = V_30 ;
V_9 = 0 ;
V_36:
F_25 ( V_27 ) ;
return V_9 ;
}
void F_26 ( void )
{
F_27 ( & V_6 ) ;
}
int F_28 ( void )
{
return F_29 ( & V_6 , & V_7 ) ;
}
