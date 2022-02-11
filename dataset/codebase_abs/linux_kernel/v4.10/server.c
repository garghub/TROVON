static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * * V_5 , * V_6 ;
int V_7 ;
F_2 ( L_1 , V_2 ) ;
F_3 ( & V_8 ) ;
V_7 = - V_9 ;
V_5 = & V_10 . V_4 ;
V_6 = NULL ;
while ( * V_5 ) {
V_6 = * V_5 ;
F_4 ( L_2 , V_6 ) ;
V_3 = F_5 ( V_6 , struct V_1 , V_11 ) ;
if ( V_2 -> V_12 . V_13 < V_3 -> V_12 . V_13 )
V_5 = & ( * V_5 ) -> V_14 ;
else if ( V_2 -> V_12 . V_13 > V_3 -> V_12 . V_13 )
V_5 = & ( * V_5 ) -> V_15 ;
else
goto error;
}
F_6 ( & V_2 -> V_11 , V_6 , V_5 ) ;
F_7 ( & V_2 -> V_11 , & V_10 ) ;
V_7 = 0 ;
error:
F_8 ( & V_8 ) ;
return V_7 ;
}
static struct V_1 * F_9 ( struct V_16 * V_17 ,
const struct V_18 * V_12 )
{
struct V_1 * V_2 ;
F_2 ( L_3 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_19 ) ;
if ( V_2 ) {
F_11 ( & V_2 -> V_20 , 1 ) ;
V_2 -> V_17 = V_17 ;
F_12 ( & V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_22 ) ;
F_13 ( & V_2 -> V_23 ) ;
F_14 ( & V_2 -> V_24 ) ;
V_2 -> V_25 = V_26 ;
V_2 -> V_27 = V_26 ;
F_14 ( & V_2 -> V_28 ) ;
F_15 ( & V_2 -> V_29 ) ;
F_16 ( & V_2 -> V_30 ,
V_31 ) ;
memcpy ( & V_2 -> V_12 , V_12 , sizeof( struct V_18 ) ) ;
V_2 -> V_12 . V_13 = V_12 -> V_13 ;
F_17 ( L_4 , V_2 , F_18 ( & V_2 -> V_20 ) ) ;
} else {
F_17 ( L_5 ) ;
}
return V_2 ;
}
struct V_1 * F_19 ( struct V_16 * V_17 ,
const struct V_18 * V_12 )
{
struct V_1 * V_2 , * V_32 ;
F_2 ( L_6 , V_17 , & V_12 -> V_13 ) ;
F_20 ( & V_17 -> V_33 ) ;
F_21 (server, &cell->servers, link) {
if ( V_2 -> V_12 . V_13 == V_12 -> V_13 )
goto V_34;
}
F_22 ( & V_17 -> V_33 ) ;
V_32 = F_9 ( V_17 , V_12 ) ;
if ( ! V_32 ) {
F_17 ( L_7 ) ;
return F_23 ( - V_35 ) ;
}
F_3 ( & V_17 -> V_33 ) ;
F_21 (server, &cell->servers, link) {
if ( V_2 -> V_12 . V_13 == V_12 -> V_13 )
goto V_36;
}
F_4 ( L_8 ) ;
V_2 = V_32 ;
if ( F_1 ( V_2 ) < 0 )
goto V_37;
F_24 ( V_17 ) ;
F_25 ( & V_2 -> V_21 , & V_17 -> V_38 ) ;
F_8 ( & V_17 -> V_33 ) ;
F_17 ( L_4 , V_2 , F_18 ( & V_2 -> V_20 ) ) ;
return V_2 ;
V_34:
F_4 ( L_9 ) ;
F_26 ( V_2 ) ;
F_22 ( & V_17 -> V_33 ) ;
V_39:
if ( ! F_27 ( & V_2 -> V_22 ) ) {
F_28 ( & V_40 ) ;
F_29 ( & V_2 -> V_22 ) ;
F_30 ( & V_40 ) ;
}
F_17 ( L_4 , V_2 , F_18 ( & V_2 -> V_20 ) ) ;
return V_2 ;
V_36:
F_4 ( L_10 ) ;
F_26 ( V_2 ) ;
F_8 ( & V_17 -> V_33 ) ;
F_31 ( V_32 ) ;
goto V_39;
V_37:
F_8 ( & V_17 -> V_33 ) ;
F_31 ( V_32 ) ;
F_32 ( V_41 L_11 ,
V_12 ) ;
F_17 ( L_12 ) ;
return F_23 ( - V_9 ) ;
}
struct V_1 * F_33 ( const struct V_42 * V_43 )
{
struct V_1 * V_2 = NULL ;
struct V_4 * V_6 ;
struct V_18 V_12 = V_43 -> V_44 . sin . V_45 ;
F_2 ( L_13 , V_43 -> V_44 . V_46 , & V_12 . V_13 ) ;
if ( V_43 -> V_44 . V_46 != V_47 ) {
F_34 ( true , L_14 ) ;
return NULL ;
}
F_20 ( & V_8 ) ;
V_6 = V_10 . V_4 ;
while ( V_6 ) {
V_2 = F_5 ( V_6 , struct V_1 , V_11 ) ;
F_4 ( L_2 , V_6 ) ;
if ( V_12 . V_13 < V_2 -> V_12 . V_13 ) {
V_6 = V_6 -> V_14 ;
} else if ( V_12 . V_13 > V_2 -> V_12 . V_13 ) {
V_6 = V_6 -> V_15 ;
} else {
F_26 ( V_2 ) ;
goto V_48;
}
}
V_2 = NULL ;
V_48:
F_22 ( & V_8 ) ;
F_35 ( V_2 , V_2 -> V_12 . V_13 , == , V_12 . V_13 ) ;
F_17 ( L_15 , V_2 ) ;
return V_2 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( L_16 , V_2 , F_18 ( & V_2 -> V_20 ) ) ;
F_4 ( L_17 , F_18 ( & V_2 -> V_20 ) ) ;
F_37 ( F_18 ( & V_2 -> V_20 ) , > , 0 ) ;
if ( F_38 ( ! F_39 ( & V_2 -> V_20 ) ) ) {
F_17 ( L_3 ) ;
return;
}
F_40 ( V_2 ) ;
F_28 ( & V_40 ) ;
if ( F_18 ( & V_2 -> V_20 ) == 0 ) {
F_41 ( & V_2 -> V_22 , & V_49 ) ;
V_2 -> V_50 = F_42 () ;
F_43 ( V_51 , & V_52 ,
V_53 * V_54 ) ;
}
F_30 ( & V_40 ) ;
F_17 ( L_18 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 ) ;
F_45 ( V_2 -> V_55 != V_2 -> V_56 ,
F_46 ( & V_2 -> V_30 ) ) ;
F_37 ( V_2 -> V_25 . V_4 , == , NULL ) ;
F_37 ( V_2 -> V_27 . V_4 , == , NULL ) ;
F_37 ( V_2 -> V_55 , == , V_2 -> V_56 ) ;
F_37 ( F_18 ( & V_2 -> V_57 ) , == , 0 ) ;
F_47 ( V_2 -> V_17 ) ;
F_31 ( V_2 ) ;
}
static void F_48 ( struct V_58 * V_59 )
{
F_49 ( V_60 ) ;
struct V_1 * V_2 ;
unsigned long V_61 , V_62 ;
T_1 V_63 ;
V_63 = F_42 () ;
F_28 ( & V_40 ) ;
while ( ! F_27 ( & V_49 ) ) {
V_2 = F_50 ( V_49 . V_64 ,
struct V_1 , V_22 ) ;
V_62 = V_2 -> V_50 + V_53 ;
if ( V_62 > V_63 ) {
V_61 = ( V_62 - V_63 ) * V_54 ;
F_51 ( V_51 , & V_52 , V_61 ) ;
break;
}
F_3 ( & V_2 -> V_17 -> V_33 ) ;
F_3 ( & V_8 ) ;
if ( F_18 ( & V_2 -> V_20 ) > 0 ) {
F_29 ( & V_2 -> V_22 ) ;
} else {
F_41 ( & V_2 -> V_22 , & V_60 ) ;
F_29 ( & V_2 -> V_21 ) ;
F_52 ( & V_2 -> V_11 , & V_10 ) ;
}
F_8 ( & V_8 ) ;
F_8 ( & V_2 -> V_17 -> V_33 ) ;
}
F_30 ( & V_40 ) ;
while ( ! F_27 ( & V_60 ) ) {
V_2 = F_50 ( V_60 . V_64 , struct V_1 , V_22 ) ;
F_53 ( & V_2 -> V_22 ) ;
F_44 ( V_2 ) ;
}
}
void T_2 F_54 ( void )
{
V_53 = 0 ;
F_51 ( V_51 , & V_52 , 0 ) ;
}
