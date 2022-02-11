static inline int F_1 ( T_1 * V_1 )
{
return F_2 ( V_2 , V_1 , V_3 ) ;
}
static int F_3 ( enum V_4 V_5 , T_1 * V_6 , T_2 V_7 , T_1 * V_1 )
{
int V_8 = - V_9 ;
struct V_10 V_11 ;
F_4 ( V_12 , V_13 ) ;
if ( F_5 ( V_13 , V_1 , V_3 ) ) {
V_8 = - V_14 ;
goto error;
}
F_6 ( V_12 , V_13 ) ;
F_7 ( V_12 , V_15 ,
NULL , NULL ) ;
F_8 ( & V_11 , V_6 , V_7 ) ;
F_9 ( V_12 , & V_11 , & V_11 , V_7 , NULL ) ;
if ( V_5 == V_16 )
V_8 = F_10 ( V_12 ) ;
else
V_8 = F_11 ( V_12 ) ;
F_12 ( V_12 ) ;
error:
return V_8 ;
}
int F_13 ( struct V_17 * V_18 )
{
struct V_19 * V_19 = (struct V_19 * ) & V_18 -> V_20 . V_6 [ V_21 ] ;
struct V_22 * V_22 ;
T_1 * V_23 ;
T_1 * V_6 = NULL ;
T_3 V_24 ;
T_2 V_7 = V_18 -> V_7 ;
int V_8 ;
V_8 = - V_9 ;
if ( V_7 <= 0 || V_7 > 1024 * 1024 || ! V_18 -> V_6 )
goto error;
V_18 -> V_25 = 16 ;
V_18 -> V_20 . V_6 [ V_26 ] = ( void * ) ( unsigned long ) V_7 ;
if ( V_7 > V_27 ) {
T_2 V_28 = F_14 ( V_7 , F_15 ( V_13 ) ) ;
V_6 = F_16 ( V_28 , V_29 ) ;
if ( ! V_6 )
return - V_30 ;
memcpy ( V_6 , V_18 -> V_6 , V_7 ) ;
memset ( V_6 + V_7 , 0x00 , V_28 - V_7 ) ;
V_23 = F_16 ( V_3 , V_29 ) ;
if ( ! V_23 ) {
V_8 = - V_30 ;
goto error;
}
V_8 = F_1 ( V_23 ) ;
if ( V_8 )
goto V_31;
V_8 = F_3 ( V_16 , V_6 , V_28 , V_23 ) ;
if ( V_8 )
goto V_31;
V_22 = F_17 ( L_1 , V_28 , 0 ) ;
if ( F_18 ( V_22 ) ) {
V_8 = F_19 ( V_22 ) ;
goto V_31;
}
V_24 = F_20 ( V_22 , V_6 , V_28 , 0 ) ;
if ( V_24 != V_28 ) {
V_8 = V_24 ;
if ( V_24 >= 0 )
V_8 = - V_30 ;
goto V_32;
}
V_18 -> V_20 . V_6 [ V_33 ] = V_23 ;
* V_19 = V_22 -> V_34 ;
F_21 ( V_19 ) ;
F_22 ( V_22 ) ;
F_23 ( V_6 ) ;
} else {
void * V_6 = F_16 ( V_7 , V_29 ) ;
if ( ! V_6 )
return - V_30 ;
V_18 -> V_20 . V_6 [ V_33 ] = V_6 ;
memcpy ( V_6 , V_18 -> V_6 , V_18 -> V_7 ) ;
}
return 0 ;
V_32:
F_22 ( V_22 ) ;
V_31:
F_23 ( V_23 ) ;
error:
F_23 ( V_6 ) ;
return V_8 ;
}
void F_24 ( struct V_17 * V_18 )
{
if ( V_18 -> V_7 > V_27 ) {
struct V_19 * V_19 = (struct V_19 * ) & V_18 -> V_20 . V_6 [ V_21 ] ;
F_25 ( V_19 ) ;
}
F_23 ( V_18 -> V_20 . V_6 [ V_33 ] ) ;
}
void F_26 ( struct V_1 * V_1 )
{
struct V_19 * V_19 = (struct V_19 * ) & V_1 -> V_20 . V_6 [ V_21 ] ;
F_27 ( V_1 , 0 ) ;
if ( F_28 ( V_1 ) &&
( T_2 ) V_1 -> V_20 . V_6 [ V_26 ] > V_27 )
F_29 ( V_19 , 0 ) ;
}
void F_30 ( struct V_1 * V_1 )
{
T_2 V_7 = ( T_2 ) V_1 -> V_20 . V_6 [ V_26 ] ;
if ( V_7 > V_27 ) {
struct V_19 * V_19 = (struct V_19 * ) & V_1 -> V_20 . V_6 [ V_21 ] ;
F_25 ( V_19 ) ;
V_19 -> V_35 = NULL ;
V_19 -> V_36 = NULL ;
}
F_23 ( V_1 -> V_20 . V_6 [ V_33 ] ) ;
V_1 -> V_20 . V_6 [ V_33 ] = NULL ;
}
void F_31 ( const struct V_1 * V_1 , struct V_37 * V_38 )
{
T_2 V_7 = ( T_2 ) V_1 -> V_20 . V_6 [ V_26 ] ;
F_32 ( V_38 , V_1 -> V_39 ) ;
if ( F_28 ( V_1 ) )
F_33 ( V_38 , L_2 ,
V_7 ,
V_7 > V_27 ? L_3 : L_4 ) ;
}
long F_34 ( const struct V_1 * V_1 , char T_4 * V_40 , T_2 V_41 )
{
T_2 V_7 = ( T_2 ) V_1 -> V_20 . V_6 [ V_26 ] ;
long V_8 ;
if ( ! V_40 || V_41 < V_7 )
return V_7 ;
if ( V_7 > V_27 ) {
struct V_19 * V_19 = (struct V_19 * ) & V_1 -> V_20 . V_6 [ V_21 ] ;
struct V_22 * V_22 ;
T_1 * V_6 ;
T_1 * V_23 = ( T_1 * ) V_1 -> V_20 . V_6 [ V_33 ] ;
T_2 V_28 = F_14 ( V_7 , F_15 ( V_13 ) ) ;
V_6 = F_16 ( V_28 , V_29 ) ;
if ( ! V_6 )
return - V_30 ;
V_22 = F_35 ( V_19 , V_42 , F_36 () ) ;
if ( F_18 ( V_22 ) ) {
V_8 = F_19 ( V_22 ) ;
goto error;
}
V_8 = F_37 ( V_22 , 0 , V_6 , V_28 ) ;
if ( V_8 >= 0 && V_8 != V_28 ) {
V_8 = - V_43 ;
goto V_32;
}
V_8 = F_3 ( V_44 , V_6 , V_28 , V_23 ) ;
if ( V_8 )
goto V_32;
V_8 = V_7 ;
if ( F_38 ( V_40 , V_6 , V_7 ) != 0 )
V_8 = - V_45 ;
V_32:
F_22 ( V_22 ) ;
error:
F_23 ( V_6 ) ;
} else {
V_8 = V_7 ;
if ( F_38 ( V_40 , V_1 -> V_20 . V_6 [ V_33 ] ,
V_7 ) != 0 )
V_8 = - V_45 ;
}
return V_8 ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_46 ) ;
}
static int T_5 F_41 ( void )
{
int V_8 = - V_9 ;
V_2 = F_42 ( V_47 , 0 , 0 ) ;
if ( F_18 ( V_2 ) ) {
V_2 = NULL ;
return - V_45 ;
}
V_8 = F_43 ( V_2 , NULL , F_44 ( V_2 ) ) ;
if ( V_8 )
goto error;
V_13 = F_45 ( V_48 ,
0 , V_49 ) ;
if ( F_18 ( V_13 ) ) {
V_13 = NULL ;
V_8 = - V_45 ;
goto error;
}
return 0 ;
error:
F_46 ( V_2 ) ;
V_2 = NULL ;
return V_8 ;
}
