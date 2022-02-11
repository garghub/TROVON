static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
unsigned int V_4 )
{
F_2 ( L_1 , V_3 , V_1 , V_1 ) ;
return F_3 ( - V_5 ) ;
}
static int F_4 ( struct V_2 * V_2 , struct V_6 * V_6 )
{
F_2 ( L_2 , V_2 , V_6 , V_6 ) ;
return - V_5 ;
}
static struct V_7 * F_5 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
struct V_7 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_14 ;
char * V_15 , * V_16 ;
bool V_17 = false ;
int V_18 ;
F_2 ( L_3 , V_8 ) ;
F_6 ( ! F_7 ( V_8 ) ) ;
V_18 = - V_19 ;
V_15 = ( char * ) F_8 ( V_20 ) ;
if ( ! V_15 )
goto V_21;
V_16 = ( char * ) F_8 ( V_20 ) ;
if ( ! V_16 )
goto V_22;
V_13 = F_9 ( F_7 ( V_8 ) ) ;
if ( F_10 ( V_23 , & V_13 -> V_4 ) ) {
static const char V_24 [] = L_4 ;
unsigned V_25 = V_8 -> V_26 . V_27 ;
V_18 = - V_28 ;
if ( V_25 < 2 || V_25 > V_29 )
goto V_30;
if ( V_8 -> V_26 . V_31 [ 0 ] == '.' ) {
V_15 [ 0 ] = '#' ;
memcpy ( V_15 + 1 , V_8 -> V_26 . V_31 , V_25 - 1 ) ;
memcpy ( V_15 + V_25 , V_24 ,
sizeof( V_24 ) ) ;
V_17 = true ;
} else {
V_15 [ 0 ] = '%' ;
memcpy ( V_15 + 1 , V_8 -> V_26 . V_31 , V_25 ) ;
memcpy ( V_15 + V_25 + 1 , V_24 ,
sizeof( V_24 ) ) ;
}
} else {
T_1 V_25 = F_11 ( F_7 ( V_8 ) ) ;
char * V_32 ;
V_18 = - V_33 ;
if ( V_25 > V_34 - 1 )
goto V_30;
V_14 = F_12 ( F_7 ( V_8 ) -> V_35 , 0 , NULL ) ;
if ( F_13 ( V_14 ) ) {
V_18 = F_14 ( V_14 ) ;
goto V_30;
}
V_18 = - V_36 ;
if ( F_15 ( V_14 ) )
goto error;
V_32 = F_16 ( V_14 ) ;
memcpy ( V_15 , V_32 , V_25 ) ;
F_17 ( V_32 ) ;
F_18 ( V_14 ) ;
V_14 = NULL ;
}
V_10 = F_19 ( V_8 -> V_37 ) ;
memcpy ( V_16 , L_5 , 5 ) ;
strcpy ( V_16 + 5 , V_10 -> V_38 -> V_39 -> V_31 ) ;
if ( V_10 -> V_38 -> type == V_40 || V_17 )
strcat ( V_16 , L_6 ) ;
F_20 ( L_7 , V_15 , V_16 ) ;
V_11 = F_21 ( V_8 , & V_41 , V_15 , V_16 ) ;
F_20 ( L_8 , V_11 ) ;
F_22 ( ( unsigned long ) V_15 ) ;
F_22 ( ( unsigned long ) V_16 ) ;
F_23 ( L_9 , V_11 ) ;
return V_11 ;
error:
F_18 ( V_14 ) ;
V_30:
F_22 ( ( unsigned long ) V_16 ) ;
V_22:
F_22 ( ( unsigned long ) V_15 ) ;
V_21:
F_23 ( L_10 , V_18 ) ;
return F_3 ( V_18 ) ;
}
struct V_7 * F_24 ( struct V_42 * V_42 )
{
struct V_7 * V_43 ;
F_2 ( L_3 , V_42 -> V_1 ) ;
V_43 = F_5 ( V_42 -> V_1 ) ;
if ( F_13 ( V_43 ) )
return V_43 ;
F_25 ( V_43 ) ;
F_26 ( V_43 , & V_44 ) ;
F_27 ( V_45 , & V_46 ,
V_47 * V_48 ) ;
F_23 ( L_9 , V_43 ) ;
return V_43 ;
}
static void F_28 ( struct V_49 * V_50 )
{
F_2 ( L_11 ) ;
if ( ! F_29 ( & V_44 ) ) {
F_30 ( & V_44 ) ;
F_27 ( V_45 , & V_46 ,
V_47 * V_48 ) ;
}
F_23 ( L_11 ) ;
}
void F_31 ( void )
{
F_2 ( L_11 ) ;
ASSERT ( F_29 ( & V_44 ) ) ;
F_32 ( & V_46 ) ;
}
