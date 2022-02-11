static int F_1 ( enum V_1 V_2 , T_1 * V_3 , T_2 V_4 , T_1 * V_5 )
{
int V_6 ;
struct V_7 V_8 ;
struct V_9 * V_10 ;
T_1 V_11 [ F_2 ( V_12 ) ] ;
V_10 = F_3 ( V_12 , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
F_4 ( & V_8 , V_3 , V_4 + ( V_2 == V_15 ? V_16 : 0 ) ) ;
F_5 ( V_10 , & V_8 , & V_8 , V_4 , V_11 ) ;
F_6 ( V_10 , V_17 , NULL , NULL ) ;
F_7 ( V_10 , 0 ) ;
F_8 ( & V_18 ) ;
if ( F_9 ( V_12 , V_5 , V_19 ) ) {
V_6 = - V_20 ;
goto error;
}
if ( V_2 == V_15 )
V_6 = F_10 ( V_10 ) ;
else
V_6 = F_11 ( V_10 ) ;
error:
F_12 ( & V_18 ) ;
F_13 ( V_10 ) ;
return V_6 ;
}
int F_14 ( struct V_21 * V_22 )
{
struct V_23 * V_23 = (struct V_23 * ) & V_22 -> V_24 . V_3 [ V_25 ] ;
struct V_26 * V_26 ;
T_1 * V_27 ;
T_1 * V_3 = NULL ;
T_3 V_28 ;
T_2 V_4 = V_22 -> V_4 ;
int V_6 ;
V_6 = - V_29 ;
if ( V_4 <= 0 || V_4 > 1024 * 1024 || ! V_22 -> V_3 )
goto error;
V_22 -> V_30 = 16 ;
V_22 -> V_24 . V_3 [ V_31 ] = ( void * ) ( unsigned long ) V_4 ;
if ( V_4 > V_32 ) {
T_2 V_33 = V_4 + V_16 ;
T_4 V_34 = 0 ;
V_3 = F_15 ( V_33 , V_13 ) ;
if ( ! V_3 )
return - V_14 ;
memcpy ( V_3 , V_22 -> V_3 , V_4 ) ;
V_27 = F_15 ( V_19 , V_13 ) ;
if ( ! V_27 ) {
V_6 = - V_14 ;
goto error;
}
V_6 = F_16 ( V_27 , V_19 ) ;
if ( F_17 ( V_6 ) )
goto V_35;
V_6 = F_1 ( V_15 , V_3 , V_4 , V_27 ) ;
if ( V_6 )
goto V_35;
V_26 = F_18 ( L_1 , V_33 , 0 ) ;
if ( F_19 ( V_26 ) ) {
V_6 = F_20 ( V_26 ) ;
goto V_35;
}
V_28 = F_21 ( V_26 , V_3 , V_33 , & V_34 ) ;
if ( V_28 != V_33 ) {
V_6 = V_28 ;
if ( V_28 >= 0 )
V_6 = - V_14 ;
goto V_36;
}
V_22 -> V_24 . V_3 [ V_37 ] = V_27 ;
* V_23 = V_26 -> V_38 ;
F_22 ( V_23 ) ;
F_23 ( V_26 ) ;
F_24 ( V_3 ) ;
} else {
void * V_3 = F_15 ( V_4 , V_13 ) ;
if ( ! V_3 )
return - V_14 ;
V_22 -> V_24 . V_3 [ V_37 ] = V_3 ;
memcpy ( V_3 , V_22 -> V_3 , V_22 -> V_4 ) ;
}
return 0 ;
V_36:
F_23 ( V_26 ) ;
V_35:
F_24 ( V_27 ) ;
error:
F_24 ( V_3 ) ;
return V_6 ;
}
void F_25 ( struct V_21 * V_22 )
{
if ( V_22 -> V_4 > V_32 ) {
struct V_23 * V_23 = (struct V_23 * ) & V_22 -> V_24 . V_3 [ V_25 ] ;
F_26 ( V_23 ) ;
}
F_24 ( V_22 -> V_24 . V_3 [ V_37 ] ) ;
}
void F_27 ( struct V_5 * V_5 )
{
struct V_23 * V_23 = (struct V_23 * ) & V_5 -> V_24 . V_3 [ V_25 ] ;
F_28 ( V_5 , 0 ) ;
if ( F_29 ( V_5 ) &&
( T_2 ) V_5 -> V_24 . V_3 [ V_31 ] > V_32 )
F_30 ( V_23 , 0 ) ;
}
void F_31 ( struct V_5 * V_5 )
{
T_2 V_4 = ( T_2 ) V_5 -> V_24 . V_3 [ V_31 ] ;
if ( V_4 > V_32 ) {
struct V_23 * V_23 = (struct V_23 * ) & V_5 -> V_24 . V_3 [ V_25 ] ;
F_26 ( V_23 ) ;
V_23 -> V_39 = NULL ;
V_23 -> V_40 = NULL ;
}
F_24 ( V_5 -> V_24 . V_3 [ V_37 ] ) ;
V_5 -> V_24 . V_3 [ V_37 ] = NULL ;
}
void F_32 ( const struct V_5 * V_5 , struct V_41 * V_42 )
{
T_2 V_4 = ( T_2 ) V_5 -> V_24 . V_3 [ V_31 ] ;
F_33 ( V_42 , V_5 -> V_43 ) ;
if ( F_29 ( V_5 ) )
F_34 ( V_42 , L_2 ,
V_4 ,
V_4 > V_32 ? L_3 : L_4 ) ;
}
long F_35 ( const struct V_5 * V_5 , char T_5 * V_44 , T_2 V_45 )
{
T_2 V_4 = ( T_2 ) V_5 -> V_24 . V_3 [ V_31 ] ;
long V_6 ;
if ( ! V_44 || V_45 < V_4 )
return V_4 ;
if ( V_4 > V_32 ) {
struct V_23 * V_23 = (struct V_23 * ) & V_5 -> V_24 . V_3 [ V_25 ] ;
struct V_26 * V_26 ;
T_1 * V_3 ;
T_1 * V_27 = ( T_1 * ) V_5 -> V_24 . V_3 [ V_37 ] ;
T_2 V_33 = V_4 + V_16 ;
T_4 V_34 = 0 ;
V_3 = F_15 ( V_33 , V_13 ) ;
if ( ! V_3 )
return - V_14 ;
V_26 = F_36 ( V_23 , V_46 , F_37 () ) ;
if ( F_19 ( V_26 ) ) {
V_6 = F_20 ( V_26 ) ;
goto error;
}
V_6 = F_38 ( V_26 , V_3 , V_33 , & V_34 ) ;
if ( V_6 >= 0 && V_6 != V_33 ) {
V_6 = - V_47 ;
goto V_36;
}
V_6 = F_1 ( V_48 , V_3 , V_33 , V_27 ) ;
if ( V_6 )
goto V_36;
V_6 = V_4 ;
if ( F_39 ( V_44 , V_3 , V_4 ) != 0 )
V_6 = - V_49 ;
V_36:
F_23 ( V_26 ) ;
error:
F_24 ( V_3 ) ;
} else {
V_6 = V_4 ;
if ( F_39 ( V_44 , V_5 -> V_24 . V_3 [ V_37 ] ,
V_4 ) != 0 )
V_6 = - V_49 ;
}
return V_6 ;
}
static int T_6 F_40 ( void )
{
int V_6 ;
V_12 = F_41 ( V_50 , 0 , V_51 ) ;
if ( F_19 ( V_12 ) ) {
V_6 = F_20 ( V_12 ) ;
F_42 ( L_5 , V_6 ) ;
return V_6 ;
}
V_6 = F_43 ( V_12 , V_16 ) ;
if ( V_6 < 0 ) {
F_42 ( L_6 , V_6 ) ;
goto V_52;
}
V_6 = F_44 ( & V_53 ) ;
if ( V_6 < 0 ) {
F_42 ( L_7 , V_6 ) ;
goto V_52;
}
return 0 ;
V_52:
F_45 ( V_12 ) ;
return V_6 ;
}
