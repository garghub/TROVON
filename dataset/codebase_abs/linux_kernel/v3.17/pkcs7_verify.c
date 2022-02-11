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
F_2 ( L_7 ,
V_4 -> V_13 , V_4 -> V_39 , V_4 -> V_40 ) ;
for ( V_37 = V_2 -> V_41 ; V_37 ; V_37 = V_37 -> V_42 , V_38 ++ ) {
if ( V_37 -> V_39 != V_4 -> V_39 ||
memcmp ( V_37 -> V_43 , V_4 -> V_43 ,
V_4 -> V_39 ) != 0 )
continue;
F_11 ( L_8 ,
V_4 -> V_13 , V_38 ) ;
if ( V_37 -> V_40 != V_4 -> V_40 ||
memcmp ( V_37 -> V_44 , V_4 -> V_44 ,
V_4 -> V_40 ) != 0 ) {
F_18 ( L_9 ,
V_4 -> V_13 ) ;
continue;
}
if ( V_37 -> V_45 -> V_46 != V_4 -> V_14 . V_46 ) {
F_18 ( L_10 ,
V_4 -> V_13 ) ;
continue;
}
V_4 -> V_47 = V_37 ;
return 0 ;
}
F_18 ( L_11 ,
V_4 -> V_13 , V_4 -> V_39 , V_4 -> V_43 ) ;
return - V_48 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_47 , * V_49 ;
int V_12 ;
F_2 ( L_12 ) ;
for ( V_49 = V_2 -> V_41 ; V_49 ; V_49 = V_49 -> V_42 )
V_49 -> V_50 = false ;
for (; ; ) {
F_12 ( L_13 , V_37 -> V_51 , V_37 -> V_52 ) ;
V_37 -> V_50 = true ;
V_12 = F_20 ( V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
F_12 ( L_14 , V_37 -> V_53 ) ;
if ( V_37 -> V_54 )
F_12 ( L_15 , V_37 -> V_54 ) ;
if ( ! V_37 -> V_54 ||
strcmp ( V_37 -> V_51 , V_37 -> V_53 ) == 0 ) {
F_12 ( L_16 ) ;
if ( V_37 -> V_55 != V_37 -> V_40 ||
memcmp ( V_37 -> V_56 , V_37 -> V_44 ,
V_37 -> V_40 ) != 0 )
return 0 ;
V_12 = F_21 ( V_37 -> V_45 , V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
V_37 -> V_47 = V_37 ;
F_12 ( L_17 ) ;
return 0 ;
}
F_12 ( L_18 , V_37 -> V_54 ) ;
for ( V_49 = V_2 -> V_41 ; V_49 ; V_49 = V_49 -> V_42 ) {
F_12 ( L_19 , V_49 -> V_13 , V_49 -> V_52 ) ;
if ( V_49 -> V_55 == V_37 -> V_40 &&
strcmp ( V_49 -> V_52 , V_37 -> V_54 ) == 0 &&
memcmp ( V_49 -> V_56 , V_37 -> V_44 ,
V_37 -> V_40 ) == 0 )
goto V_57;
}
F_12 ( L_20 ) ;
return 0 ;
V_57:
F_12 ( L_14 , V_49 -> V_51 ) ;
if ( V_49 -> V_50 ) {
F_18 ( L_21 ,
V_4 -> V_13 ) ;
return 0 ;
}
V_12 = F_21 ( V_49 -> V_45 , V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
V_37 -> V_47 = V_49 ;
if ( V_37 == V_49 ) {
F_12 ( L_17 ) ;
return 0 ;
}
V_37 = V_49 ;
F_22 () ;
}
}
static int F_23 ( struct V_1 * V_2 ,
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
F_11 ( L_23 ,
V_4 -> V_47 -> V_13 , V_4 -> V_13 ) ;
V_12 = F_24 ( V_4 -> V_47 -> V_45 , & V_4 -> V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
F_11 ( L_24 , V_4 -> V_13 ) ;
return F_19 ( V_2 , V_4 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_36 * V_37 ;
int V_12 , V_58 ;
F_2 ( L_12 ) ;
for ( V_58 = 0 , V_37 = V_2 -> V_41 ; V_37 ; V_37 = V_37 -> V_42 , V_58 ++ ) {
V_12 = F_20 ( V_37 ) ;
if ( V_12 < 0 )
return V_12 ;
F_12 ( L_25 , V_58 , V_37 -> V_54 ) ;
}
for ( V_4 = V_2 -> V_59 ; V_4 ; V_4 = V_4 -> V_42 ) {
V_12 = F_23 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
F_16 ( L_6 , V_12 ) ;
return V_12 ;
}
}
F_16 ( L_26 ) ;
return 0 ;
}
