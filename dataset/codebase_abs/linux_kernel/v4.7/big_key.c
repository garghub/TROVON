static inline int F_1 ( T_1 * V_1 )
{
return F_2 ( V_2 , V_1 , V_3 ) ;
}
static int F_3 ( enum V_4 V_5 , T_1 * V_6 , T_2 V_7 , T_1 * V_1 )
{
int V_8 = - V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
if ( F_4 ( V_14 , V_1 , V_3 ) ) {
V_8 = - V_15 ;
goto error;
}
V_13 . V_16 = 0 ;
V_13 . V_17 = V_14 ;
F_5 ( & V_11 , V_6 , V_7 ) ;
if ( V_5 == V_18 )
V_8 = F_6 ( & V_13 , & V_11 , & V_11 , V_7 ) ;
else
V_8 = F_7 ( & V_13 , & V_11 , & V_11 , V_7 ) ;
error:
return V_8 ;
}
int F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_21 = (struct V_21 * ) & V_20 -> V_22 . V_6 [ V_23 ] ;
struct V_24 * V_24 ;
T_1 * V_25 ;
T_1 * V_6 = NULL ;
T_3 V_26 ;
T_2 V_7 = V_20 -> V_7 ;
int V_8 ;
V_8 = - V_9 ;
if ( V_7 <= 0 || V_7 > 1024 * 1024 || ! V_20 -> V_6 )
goto error;
V_20 -> V_27 = 16 ;
V_20 -> V_22 . V_6 [ V_28 ] = ( void * ) ( unsigned long ) V_7 ;
if ( V_7 > V_29 ) {
T_2 V_30 = F_9 ( V_7 , F_10 ( V_14 ) ) ;
V_6 = F_11 ( V_30 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
memcpy ( V_6 , V_20 -> V_6 , V_7 ) ;
memset ( V_6 + V_7 , 0x00 , V_30 - V_7 ) ;
V_25 = F_11 ( V_3 , V_31 ) ;
if ( ! V_25 ) {
V_8 = - V_32 ;
goto error;
}
V_8 = F_1 ( V_25 ) ;
if ( V_8 )
goto V_33;
V_8 = F_3 ( V_18 , V_6 , V_30 , V_25 ) ;
if ( V_8 )
goto V_33;
V_24 = F_12 ( L_1 , V_30 , 0 ) ;
if ( F_13 ( V_24 ) ) {
V_8 = F_14 ( V_24 ) ;
goto V_33;
}
V_26 = F_15 ( V_24 , V_6 , V_30 , 0 ) ;
if ( V_26 != V_30 ) {
V_8 = V_26 ;
if ( V_26 >= 0 )
V_8 = - V_32 ;
goto V_34;
}
V_20 -> V_22 . V_6 [ V_35 ] = V_25 ;
* V_21 = V_24 -> V_36 ;
F_16 ( V_21 ) ;
F_17 ( V_24 ) ;
F_18 ( V_6 ) ;
} else {
void * V_6 = F_11 ( V_7 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
V_20 -> V_22 . V_6 [ V_35 ] = V_6 ;
memcpy ( V_6 , V_20 -> V_6 , V_20 -> V_7 ) ;
}
return 0 ;
V_34:
F_17 ( V_24 ) ;
V_33:
F_18 ( V_25 ) ;
error:
F_18 ( V_6 ) ;
return V_8 ;
}
void F_19 ( struct V_19 * V_20 )
{
if ( V_20 -> V_7 > V_29 ) {
struct V_21 * V_21 = (struct V_21 * ) & V_20 -> V_22 . V_6 [ V_23 ] ;
F_20 ( V_21 ) ;
}
F_18 ( V_20 -> V_22 . V_6 [ V_35 ] ) ;
}
void F_21 ( struct V_1 * V_1 )
{
struct V_21 * V_21 = (struct V_21 * ) & V_1 -> V_22 . V_6 [ V_23 ] ;
F_22 ( V_1 , 0 ) ;
if ( F_23 ( V_1 ) &&
( T_2 ) V_1 -> V_22 . V_6 [ V_28 ] > V_29 )
F_24 ( V_21 , 0 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
T_2 V_7 = ( T_2 ) V_1 -> V_22 . V_6 [ V_28 ] ;
if ( V_7 > V_29 ) {
struct V_21 * V_21 = (struct V_21 * ) & V_1 -> V_22 . V_6 [ V_23 ] ;
F_20 ( V_21 ) ;
V_21 -> V_37 = NULL ;
V_21 -> V_38 = NULL ;
}
F_18 ( V_1 -> V_22 . V_6 [ V_35 ] ) ;
V_1 -> V_22 . V_6 [ V_35 ] = NULL ;
}
void F_26 ( const struct V_1 * V_1 , struct V_39 * V_40 )
{
T_2 V_7 = ( T_2 ) V_1 -> V_22 . V_6 [ V_28 ] ;
F_27 ( V_40 , V_1 -> V_41 ) ;
if ( F_23 ( V_1 ) )
F_28 ( V_40 , L_2 ,
V_7 ,
V_7 > V_29 ? L_3 : L_4 ) ;
}
long F_29 ( const struct V_1 * V_1 , char T_4 * V_42 , T_2 V_43 )
{
T_2 V_7 = ( T_2 ) V_1 -> V_22 . V_6 [ V_28 ] ;
long V_8 ;
if ( ! V_42 || V_43 < V_7 )
return V_7 ;
if ( V_7 > V_29 ) {
struct V_21 * V_21 = (struct V_21 * ) & V_1 -> V_22 . V_6 [ V_23 ] ;
struct V_24 * V_24 ;
T_1 * V_6 ;
T_1 * V_25 = ( T_1 * ) V_1 -> V_22 . V_6 [ V_35 ] ;
T_2 V_30 = F_9 ( V_7 , F_10 ( V_14 ) ) ;
V_6 = F_11 ( V_30 , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
V_24 = F_30 ( V_21 , V_44 , F_31 () ) ;
if ( F_13 ( V_24 ) ) {
V_8 = F_14 ( V_24 ) ;
goto error;
}
V_8 = F_32 ( V_24 , 0 , V_6 , V_30 ) ;
if ( V_8 >= 0 && V_8 != V_30 ) {
V_8 = - V_45 ;
goto V_34;
}
V_8 = F_3 ( V_46 , V_6 , V_30 , V_25 ) ;
if ( V_8 )
goto V_34;
V_8 = V_7 ;
if ( F_33 ( V_42 , V_6 , V_7 ) != 0 )
V_8 = - V_47 ;
V_34:
F_17 ( V_24 ) ;
error:
F_18 ( V_6 ) ;
} else {
V_8 = V_7 ;
if ( F_33 ( V_42 , V_1 -> V_22 . V_6 [ V_35 ] ,
V_7 ) != 0 )
V_8 = - V_47 ;
}
return V_8 ;
}
static int T_5 F_34 ( void )
{
return F_35 ( & V_48 ) ;
}
static int T_5 F_36 ( void )
{
int V_8 = - V_9 ;
V_2 = F_37 ( V_49 , 0 , 0 ) ;
if ( F_13 ( V_2 ) ) {
V_2 = NULL ;
return - V_47 ;
}
V_8 = F_38 ( V_2 , NULL , F_39 ( V_2 ) ) ;
if ( V_8 )
goto error;
V_14 = F_40 ( V_50 , 0 , 0 ) ;
if ( F_13 ( V_14 ) ) {
V_14 = NULL ;
V_8 = - V_47 ;
goto error;
}
return 0 ;
error:
F_41 ( V_2 ) ;
V_2 = NULL ;
return V_8 ;
}
