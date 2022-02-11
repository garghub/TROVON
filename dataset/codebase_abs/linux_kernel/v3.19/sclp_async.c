static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
strncat ( V_4 , F_2 () -> V_5 ,
sizeof( F_2 () -> V_5 ) ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static int F_4 ( struct V_7 * V_8 , int V_9 ,
void T_1 * V_10 , T_2 * V_11 ,
T_3 * V_12 )
{
unsigned long V_13 ;
int V_14 , V_15 ;
char V_16 [ 3 ] ;
if ( ! * V_11 || ( * V_12 && ! V_9 ) ) {
* V_11 = 0 ;
return 0 ;
}
if ( ! V_9 ) {
V_14 = snprintf ( V_16 , sizeof( V_16 ) , L_1 , V_17 ) ;
V_15 = F_5 ( V_10 , V_16 , sizeof( V_16 ) ) ;
if ( V_15 != 0 )
return - V_18 ;
} else {
V_14 = * V_11 ;
V_15 = F_6 ( V_10 , V_14 , 0 , & V_13 ) ;
if ( V_15 )
return V_15 ;
if ( V_13 != 0 && V_13 != 1 )
return - V_19 ;
V_17 = V_13 ;
}
* V_11 = V_14 ;
* V_12 += V_14 ;
return 0 ;
}
static int F_3 ( char * V_20 )
{
struct V_21 * V_22 ;
int V_15 ;
unsigned long V_23 ;
if ( ! V_17 )
return 0 ;
V_24 -> V_25 . V_26 . type = V_27 ;
V_24 -> V_25 . V_28 = 0xA5 ;
V_24 -> V_25 . V_29 = 0x00 ;
V_22 = & V_24 -> V_25 ;
V_30 -> V_31 = V_32 ;
V_30 -> V_24 = V_24 ;
V_30 -> V_33 = V_34 ;
strncpy ( V_24 -> V_25 . V_4 , V_20 , sizeof( V_24 -> V_25 . V_4 ) ) ;
strncpy ( V_24 -> V_25 . V_35 , V_36 ,
sizeof( V_24 -> V_25 . V_35 ) ) ;
V_24 -> V_25 . V_26 . V_37 = sizeof( V_24 -> V_25 ) ;
V_24 -> V_26 . V_37 = sizeof( V_24 -> V_25 ) + sizeof( V_24 -> V_26 ) ;
V_24 -> V_26 . V_38 = V_39 ;
V_15 = F_7 ( V_30 ) ;
if ( V_15 )
return V_15 ;
F_8 ( & V_40 , V_23 ) ;
while ( V_30 -> V_33 != V_41 &&
V_30 -> V_33 != V_42 ) {
F_9 () ;
}
F_10 ( & V_40 , V_23 ) ;
if ( V_30 -> V_33 != V_41 )
return - V_43 ;
V_15 = ( (struct V_44 * )
V_30 -> V_24 ) -> V_26 . V_45 ;
if ( V_15 != 0x0020 )
return - V_43 ;
if ( V_22 -> V_26 . V_23 != 0x80 )
return - V_43 ;
return V_15 ;
}
static int T_4 F_11 ( void )
{
int V_15 ;
V_15 = F_12 ( & V_46 ) ;
if ( V_15 )
return V_15 ;
V_15 = - V_47 ;
if ( ! ( V_46 . V_48 & V_49 ) )
goto V_50;
V_15 = - V_51 ;
V_52 = F_13 ( V_53 ) ;
if ( ! V_52 )
goto V_50;
V_30 = F_14 ( sizeof( struct V_54 ) , V_55 ) ;
V_24 = (struct V_44 * ) F_15 ( V_55 | V_56 ) ;
if ( ! V_30 || ! V_24 )
goto V_57;
V_15 = F_16 ( & V_58 ,
& V_59 ) ;
if ( ! V_15 )
goto V_60;
V_57:
F_17 ( V_30 ) ;
F_18 ( ( unsigned long ) V_24 ) ;
F_19 ( V_52 ) ;
V_50:
F_20 ( & V_46 ) ;
V_60:
return V_15 ;
}
static void T_5 F_21 ( void )
{
F_22 ( & V_58 ,
& V_59 ) ;
F_19 ( V_52 ) ;
F_20 ( & V_46 ) ;
F_18 ( ( unsigned long ) V_24 ) ;
F_17 ( V_30 ) ;
}
