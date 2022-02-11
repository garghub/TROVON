static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_1 = V_2 -> V_6 . V_7 [ V_8 ] ;
if ( V_1 )
F_2 ( V_4 , L_1 , V_1 -> V_9 , V_1 -> V_10 ) ;
}
void F_3 ( struct V_5 * V_1 )
{
if ( V_1 ) {
F_4 ( V_1 -> V_1 ) ;
F_4 ( V_1 ) ;
}
}
static void F_5 ( void * V_11 , void * V_12 )
{
F_3 ( V_11 ) ;
F_6 ( V_12 ) ;
}
static void F_7 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_14 -> V_7 ;
if ( V_15 == - V_18 )
return;
V_17 -> V_15 = V_15 ;
F_8 ( & V_17 -> V_19 ) ;
}
int F_9 ( const struct V_5 * V_20 ,
const struct V_21 * V_22 )
{
struct V_16 V_17 ;
struct V_23 * V_24 ;
struct V_25 * V_14 ;
struct V_26 V_27 , V_28 ;
const char * V_29 ;
char V_30 [ V_31 ] ;
void * V_32 ;
unsigned int V_33 ;
int V_34 = - V_35 ;
F_10 ( L_2 , V_36 ) ;
F_11 ( ! V_20 ) ;
F_11 ( ! V_22 ) ;
F_11 ( ! V_22 -> V_37 ) ;
F_11 ( ! V_22 -> V_38 ) ;
V_29 = V_22 -> V_10 ;
if ( strcmp ( V_22 -> V_10 , L_3 ) == 0 ) {
if ( snprintf ( V_30 , V_31 ,
L_4 , V_22 -> V_39
) >= V_31 )
return - V_40 ;
V_29 = V_30 ;
}
V_24 = F_12 ( V_29 , 0 , 0 ) ;
if ( F_13 ( V_24 ) )
return F_14 ( V_24 ) ;
V_14 = F_15 ( V_24 , V_41 ) ;
if ( ! V_14 )
goto V_42;
V_34 = F_16 ( V_24 , V_20 -> V_1 , V_20 -> V_43 ) ;
if ( V_34 )
goto V_44;
V_33 = F_17 ( V_24 ) ;
V_32 = F_18 ( V_33 , V_41 ) ;
if ( ! V_32 )
goto V_44;
F_19 ( & V_27 , V_22 -> V_38 , V_22 -> V_45 ) ;
F_19 ( & V_28 , V_32 , V_33 ) ;
F_20 ( V_14 , & V_27 , & V_28 , V_22 -> V_45 ,
V_33 ) ;
F_21 ( & V_17 . V_19 ) ;
F_22 ( V_14 , V_46 |
V_47 ,
F_7 , & V_17 ) ;
V_34 = F_23 ( V_14 ) ;
if ( V_34 == - V_18 ) {
F_24 ( & V_17 . V_19 ) ;
V_34 = V_17 . V_15 ;
}
if ( V_34 < 0 )
goto V_48;
if ( V_14 -> V_49 != V_22 -> V_50 ||
memcmp ( V_22 -> V_37 , V_32 , V_22 -> V_50 ) != 0 )
V_34 = - V_51 ;
V_48:
F_4 ( V_32 ) ;
V_44:
F_25 ( V_14 ) ;
V_42:
F_26 ( V_24 ) ;
F_10 ( L_5 , V_36 , V_34 ) ;
return V_34 ;
}
static int F_27 ( const struct V_1 * V_1 ,
const struct V_21 * V_22 )
{
const struct V_5 * V_52 = V_1 -> V_6 . V_7 [ V_8 ] ;
return F_9 ( V_52 , V_22 ) ;
}
