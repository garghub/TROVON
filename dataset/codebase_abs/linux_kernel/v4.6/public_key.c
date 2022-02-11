static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_1 = V_2 -> V_6 . V_7 [ V_8 ] ;
if ( V_1 )
F_2 ( V_4 , L_1 , V_1 -> V_9 , V_1 -> V_10 ) ;
}
void F_3 ( void * V_6 )
{
struct V_5 * V_1 = V_6 ;
if ( V_1 )
F_4 ( V_1 -> V_1 ) ;
F_4 ( V_1 ) ;
}
static void F_5 ( struct V_11 * V_12 , int V_13 )
{
struct V_14 * V_15 = V_12 -> V_7 ;
if ( V_13 == - V_16 )
return;
V_15 -> V_13 = V_13 ;
F_6 ( & V_15 -> V_17 ) ;
}
int F_7 ( const struct V_5 * V_18 ,
const struct V_19 * V_20 )
{
struct V_14 V_15 ;
struct V_21 * V_22 ;
struct V_23 * V_12 ;
struct V_24 V_25 , V_26 ;
const char * V_27 ;
char V_28 [ V_29 ] ;
void * V_30 ;
unsigned int V_31 ;
int V_32 = - V_33 ;
F_8 ( L_2 , V_34 ) ;
F_9 ( ! V_18 ) ;
F_9 ( ! V_20 ) ;
F_9 ( ! V_20 -> V_35 ) ;
F_9 ( ! V_20 -> V_36 ) ;
V_27 = V_20 -> V_10 ;
if ( strcmp ( V_20 -> V_10 , L_3 ) == 0 ) {
if ( snprintf ( V_28 , V_29 ,
L_4 , V_20 -> V_37
) >= V_29 )
return - V_38 ;
V_27 = V_28 ;
}
V_22 = F_10 ( V_27 , 0 , 0 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
V_12 = F_13 ( V_22 , V_39 ) ;
if ( ! V_12 )
goto V_40;
V_32 = F_14 ( V_22 , V_18 -> V_1 , V_18 -> V_41 ) ;
if ( V_32 )
goto V_42;
V_31 = F_15 ( V_22 ) ;
V_30 = F_16 ( V_31 , V_39 ) ;
if ( ! V_30 )
goto V_42;
F_17 ( & V_25 , V_20 -> V_36 , V_20 -> V_43 ) ;
F_17 ( & V_26 , V_30 , V_31 ) ;
F_18 ( V_12 , & V_25 , & V_26 , V_20 -> V_43 ,
V_31 ) ;
F_19 ( & V_15 . V_17 ) ;
F_20 ( V_12 , V_44 |
V_45 ,
F_5 , & V_15 ) ;
V_32 = F_21 ( V_12 ) ;
if ( V_32 == - V_16 ) {
F_22 ( & V_15 . V_17 ) ;
V_32 = V_15 . V_13 ;
}
if ( V_32 < 0 )
goto V_46;
if ( V_12 -> V_47 != V_20 -> V_48 ||
memcmp ( V_20 -> V_35 , V_30 , V_20 -> V_48 ) != 0 )
V_32 = - V_49 ;
V_46:
F_4 ( V_30 ) ;
V_42:
F_23 ( V_12 ) ;
V_40:
F_24 ( V_22 ) ;
F_8 ( L_5 , V_34 , V_32 ) ;
return V_32 ;
}
static int F_25 ( const struct V_1 * V_1 ,
const struct V_19 * V_20 )
{
const struct V_5 * V_50 = V_1 -> V_6 . V_7 [ V_8 ] ;
return F_7 ( V_50 , V_20 ) ;
}
