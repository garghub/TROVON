int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_4 ;
T_1 V_5 ;
char * V_6 ;
int V_7 ;
F_2 ( L_1 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_2 , V_2 -> V_8 . V_10 ) ;
V_4 = F_3 ( F_4 ( V_2 ) -> V_11 , 0 ,
V_12 , V_3 ) ;
if ( F_5 ( V_4 ) ) {
V_7 = F_6 ( V_4 ) ;
goto V_13;
}
V_7 = - V_14 ;
if ( F_7 ( V_4 ) )
goto V_15;
V_6 = F_8 ( V_4 ) ;
V_5 = V_2 -> V_16 . V_5 ;
F_9 ( L_2 , ( int ) V_5 , ( int ) V_5 , V_6 ) ;
if ( V_5 > 2 &&
( V_6 [ 0 ] == '%' || V_6 [ 0 ] == '#' ) &&
V_6 [ V_5 - 1 ] == '.'
) {
F_9 ( L_3 ) ;
F_10 ( & V_2 -> V_17 ) ;
F_11 ( V_18 , & V_2 -> V_19 ) ;
V_2 -> V_20 . V_21 |= V_22 ;
F_12 ( & V_2 -> V_17 ) ;
}
V_7 = 0 ;
F_13 ( V_4 ) ;
V_15:
F_14 ( V_4 ) ;
V_13:
F_15 ( L_4 , V_7 ) ;
return V_7 ;
}
static struct V_23 * F_16 ( struct V_24 * V_25 ,
struct V_23 * V_23 ,
unsigned int V_19 )
{
F_2 ( L_5 , V_25 , V_23 , V_23 ) ;
return F_17 ( - V_26 ) ;
}
static int F_18 ( struct V_24 * V_24 , struct V_27 * V_27 )
{
F_2 ( L_6 , V_24 , V_27 , V_27 ) ;
return - V_26 ;
}
static struct V_28 * F_19 ( struct V_23 * V_29 )
{
struct V_30 * V_31 ;
struct V_28 * V_32 ;
struct V_1 * V_2 ;
struct V_4 * V_4 ;
char * V_33 , * V_34 ;
bool V_35 = false ;
int V_7 ;
F_2 ( L_7 , V_29 ) ;
F_20 ( ! F_21 ( V_29 ) ) ;
V_7 = - V_36 ;
V_33 = ( char * ) F_22 ( V_37 ) ;
if ( ! V_33 )
goto V_38;
V_34 = ( char * ) F_22 ( V_37 ) ;
if ( ! V_34 )
goto V_39;
V_2 = F_23 ( F_21 ( V_29 ) ) ;
if ( F_24 ( V_40 , & V_2 -> V_19 ) ) {
static const char V_41 [] = L_8 ;
unsigned V_5 = V_29 -> V_42 . V_43 ;
V_7 = - V_44 ;
if ( V_5 < 2 || V_5 > V_45 )
goto V_46;
if ( V_29 -> V_42 . V_47 [ 0 ] == '.' ) {
V_33 [ 0 ] = '#' ;
memcpy ( V_33 + 1 , V_29 -> V_42 . V_47 , V_5 - 1 ) ;
memcpy ( V_33 + V_5 , V_41 ,
sizeof( V_41 ) ) ;
V_35 = true ;
} else {
V_33 [ 0 ] = '%' ;
memcpy ( V_33 + 1 , V_29 -> V_42 . V_47 , V_5 ) ;
memcpy ( V_33 + V_5 + 1 , V_41 ,
sizeof( V_41 ) ) ;
}
} else {
T_2 V_5 = F_25 ( F_21 ( V_29 ) ) ;
char * V_6 ;
V_7 = - V_48 ;
if ( V_5 > V_49 - 1 )
goto V_46;
V_4 = F_26 ( F_21 ( V_29 ) -> V_11 , 0 , NULL ) ;
if ( F_5 ( V_4 ) ) {
V_7 = F_6 ( V_4 ) ;
goto V_46;
}
V_7 = - V_14 ;
if ( F_7 ( V_4 ) )
goto error;
V_6 = F_27 ( V_4 ) ;
memcpy ( V_33 , V_6 , V_5 ) ;
F_28 ( V_6 ) ;
F_14 ( V_4 ) ;
V_4 = NULL ;
}
V_31 = F_29 ( V_29 -> V_50 ) ;
memcpy ( V_34 , L_9 , 5 ) ;
strcpy ( V_34 + 5 , V_31 -> V_51 -> V_52 -> V_47 ) ;
if ( V_31 -> V_51 -> type == V_53 || V_35 )
strcat ( V_34 , L_10 ) ;
F_9 ( L_11 , V_33 , V_34 ) ;
V_32 = F_30 ( & V_54 , 0 , V_33 , V_34 ) ;
F_9 ( L_12 , V_32 ) ;
F_31 ( ( unsigned long ) V_33 ) ;
F_31 ( ( unsigned long ) V_34 ) ;
F_15 ( L_13 , V_32 ) ;
return V_32 ;
error:
F_14 ( V_4 ) ;
V_46:
F_31 ( ( unsigned long ) V_34 ) ;
V_39:
F_31 ( ( unsigned long ) V_33 ) ;
V_38:
F_15 ( L_4 , V_7 ) ;
return F_17 ( V_7 ) ;
}
struct V_28 * F_32 ( struct V_55 * V_55 )
{
struct V_28 * V_56 ;
F_2 ( L_7 , V_55 -> V_23 ) ;
V_56 = F_19 ( V_55 -> V_23 ) ;
if ( F_5 ( V_56 ) )
return V_56 ;
F_33 ( V_56 ) ;
F_34 ( V_56 , & V_57 ) ;
F_35 ( V_58 , & V_59 ,
V_60 * V_61 ) ;
F_15 ( L_13 , V_56 ) ;
return V_56 ;
}
static void F_36 ( struct V_62 * V_63 )
{
F_2 ( L_14 ) ;
if ( ! F_37 ( & V_57 ) ) {
F_38 ( & V_57 ) ;
F_35 ( V_58 , & V_59 ,
V_60 * V_61 ) ;
}
F_15 ( L_14 ) ;
}
void F_39 ( void )
{
F_2 ( L_14 ) ;
ASSERT ( F_37 ( & V_57 ) ) ;
F_40 ( & V_59 ) ;
}
