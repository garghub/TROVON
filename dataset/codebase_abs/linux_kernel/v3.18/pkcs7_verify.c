static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 , V_10 ;
void * V_11 ;
int V_12 ;
F_2 ( L_1 , V_4 -> V_13 , V_4 -> V_14 . V_15 ) ;
if ( V_4 -> V_14 . V_15 >= V_16 ||
! V_17 [ V_4 -> V_14 . V_15 ] )
return - V_18 ;
V_6 = F_3 ( V_17 [ V_4 -> V_14 . V_15 ] ,
0 , 0 ) ;
if ( F_4 ( V_6 ) )
return ( F_5 ( V_6 ) == - V_19 ) ? - V_18 : F_5 ( V_6 ) ;
V_10 = F_6 ( V_6 ) + sizeof( * V_8 ) ;
V_4 -> V_14 . V_9 = V_9 = F_7 ( V_6 ) ;
V_12 = - V_20 ;
V_11 = F_8 ( V_9 + V_10 , V_21 ) ;
if ( ! V_11 )
goto V_22;
V_8 = V_11 + V_9 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_23 = V_24 ;
V_12 = F_9 ( V_8 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_10 ( V_8 , V_2 -> V_25 , V_2 -> V_26 , V_11 ) ;
if ( V_12 < 0 )
goto error;
F_11 ( L_2 , 8 , V_11 ) ;
if ( V_4 -> V_27 ) {
T_2 V_28 ;
if ( V_4 -> V_29 != V_4 -> V_14 . V_9 ) {
F_12 ( L_3 ,
V_4 -> V_13 , V_4 -> V_29 ) ;
V_12 = - V_30 ;
goto error;
}
if ( memcmp ( V_11 , V_4 -> V_27 , V_4 -> V_29 ) != 0 ) {
F_12 ( L_4 ,
V_4 -> V_13 ) ;
V_12 = - V_31 ;
goto error;
}
memset ( V_11 , 0 , V_4 -> V_14 . V_9 ) ;
V_12 = F_9 ( V_8 ) ;
if ( V_12 < 0 )
goto error;
V_28 = V_32 | V_33 ;
V_12 = F_13 ( V_8 , & V_28 , 1 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_10 ( V_8 , V_4 -> V_34 ,
V_4 -> V_35 , V_11 ) ;
if ( V_12 < 0 )
goto error;
F_11 ( L_5 , 8 , V_11 ) ;
}
V_4 -> V_14 . V_11 = V_11 ;
V_11 = NULL ;
error:
F_14 ( V_11 ) ;
V_22:
F_15 ( V_6 ) ;
F_16 ( L_6 , V_12 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_36 * V_37 ;
unsigned V_38 = 1 ;
F_2 ( L_7 , V_4 -> V_13 ) ;
for ( V_37 = V_2 -> V_39 ; V_37 ; V_37 = V_37 -> V_40 , V_38 ++ ) {
if ( ! F_18 ( V_37 -> V_41 , V_4 -> V_42 ) )
continue;
F_11 ( L_8 ,
V_4 -> V_13 , V_38 ) ;
if ( V_37 -> V_43 -> V_44 != V_4 -> V_14 . V_44 ) {
F_19 ( L_9 ,
V_4 -> V_13 ) ;
continue;
}
V_4 -> V_45 = V_37 ;
return 0 ;
}
F_12 ( L_10 ,
V_4 -> V_13 ,
V_4 -> V_42 -> V_46 , V_4 -> V_42 -> V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_45 , * V_47 ;
int V_12 ;
F_2 ( L_11 ) ;
for ( V_47 = V_2 -> V_39 ; V_47 ; V_47 = V_47 -> V_40 )
V_47 -> V_48 = false ;
for (; ; ) {
F_12 ( L_12 ,
V_37 -> V_49 ,
V_37 -> V_50 , V_37 -> V_51 ) ;
V_37 -> V_48 = true ;
V_12 = F_21 ( V_37 ) ;
if ( V_12 < 0 )
goto V_52;
F_12 ( L_13 , V_37 -> V_53 ) ;
if ( V_37 -> V_54 )
F_12 ( L_14 ,
V_37 -> V_54 -> V_46 , V_37 -> V_54 -> V_25 ) ;
if ( ! V_37 -> V_54 ||
strcmp ( V_37 -> V_49 , V_37 -> V_53 ) == 0 ) {
F_12 ( L_15 ) ;
if ( V_37 -> V_55 != V_37 -> V_56 ||
memcmp ( V_37 -> V_57 , V_37 -> V_58 ,
V_37 -> V_56 ) != 0 )
return 0 ;
V_12 = F_22 ( V_37 -> V_43 , V_37 ) ;
if ( V_12 < 0 )
goto V_52;
V_37 -> V_45 = V_37 ;
F_12 ( L_16 ) ;
return 0 ;
}
F_12 ( L_17 ,
V_37 -> V_54 -> V_46 , V_37 -> V_54 -> V_25 ) ;
for ( V_47 = V_2 -> V_39 ; V_47 ; V_47 = V_47 -> V_40 ) {
if ( ! V_47 -> V_59 )
continue;
F_12 ( L_18 ,
V_47 -> V_13 , V_47 -> V_59 -> V_46 , V_47 -> V_59 -> V_25 ) ;
if ( F_18 ( V_47 -> V_59 , V_37 -> V_54 ) )
goto V_60;
}
F_12 ( L_19 ) ;
return 0 ;
V_60:
F_12 ( L_20 , V_47 -> V_49 ) ;
if ( V_47 -> V_48 ) {
F_19 ( L_21 ,
V_4 -> V_13 ) ;
return 0 ;
}
V_12 = F_22 ( V_47 -> V_43 , V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
V_37 -> V_45 = V_47 ;
if ( V_37 == V_47 ) {
F_12 ( L_16 ) ;
return 0 ;
}
V_37 = V_47 ;
F_23 () ;
}
V_52:
if ( V_12 == - V_18 )
return 0 ;
return V_12 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 ;
F_2 ( L_22 , V_4 -> V_13 ) ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_17 ( V_2 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! V_4 -> V_45 )
return 0 ;
F_11 ( L_23 ,
V_4 -> V_45 -> V_13 , V_4 -> V_13 ) ;
V_12 = F_25 ( V_4 -> V_45 -> V_43 , & V_4 -> V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
F_11 ( L_24 , V_4 -> V_13 ) ;
return F_20 ( V_2 , V_4 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_36 * V_37 ;
int V_61 = - V_18 ;
int V_12 , V_62 ;
F_2 ( L_11 ) ;
for ( V_62 = 0 , V_37 = V_2 -> V_39 ; V_37 ; V_37 = V_37 -> V_40 , V_62 ++ ) {
V_12 = F_21 ( V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
F_12 ( L_25 ,
V_62 , V_37 -> V_54 -> V_46 , V_37 -> V_54 -> V_25 ) ;
}
for ( V_4 = V_2 -> V_63 ; V_4 ; V_4 = V_4 -> V_40 ) {
V_12 = F_24 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_18 ) {
V_4 -> V_64 = true ;
continue;
}
F_16 ( L_6 , V_12 ) ;
return V_12 ;
}
V_61 = 0 ;
}
F_16 ( L_6 , V_61 ) ;
return V_61 ;
}
