int F_1 ( T_1 V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 ;
T_3 V_8 = 0 ;
struct V_9 * V_10 = V_1 ;
char * V_11 = F_2 ( V_12 , V_13 ) ;
if ( ! V_11 )
return - V_14 ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_15 V_16 * ) V_11 ,
V_12 , & V_8 ) ;
F_4 ( V_5 ) ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 )
V_6 = V_7 ;
else
V_6 = 0 ;
break;
}
V_6 = F_7 ( V_10 , V_4 , V_11 , V_7 ) ;
if ( V_6 )
break;
V_4 += V_12 ;
}
F_8 ( V_11 ) ;
return V_6 ;
}
int F_9 ( T_1 V_1 , struct V_2 * V_3 ,
unsigned int V_4 )
{
char * V_11 , * V_17 ;
unsigned int V_18 = 0 ;
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 , V_19 = 0 ;
T_3 V_8 = 0 ;
static int V_20 ;
INT V_21 = V_22 ;
struct V_9 * V_10 = V_1 ;
int V_23 ;
V_11 = F_2 ( V_12 , V_24 ) ;
V_17 = F_2 ( V_12 , V_24 ) ;
if ( ! V_11 || ! V_17 ) {
F_8 ( V_11 ) ;
F_8 ( V_17 ) ;
return - V_14 ;
}
V_19 = ( V_4 == V_25 ) ? 1 : 0 ;
memset ( V_17 , 0 , V_12 ) ;
memset ( V_11 , 0 , V_12 ) ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_15 V_16 * ) V_11 ,
V_12 , & V_8 ) ;
F_4 ( V_5 ) ;
V_20 ++ ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 )
V_6 = V_7 ;
else
V_6 = 0 ;
break;
}
V_23 = F_10 ( V_10 , V_4 ,
V_17 , V_7 ) ;
if ( V_23 < 0 ) {
V_21 = V_23 ;
goto exit;
}
V_18 ++ ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_17 , V_11 , V_7 ) ) {
V_21 = - V_26 ;
goto exit;
}
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_17 [ V_7 ] !=
* ( unsigned int * ) & V_11 [ V_7 ] ) {
V_21 = - V_26 ;
goto exit;
}
V_7 -= 4 ;
}
}
V_4 += V_12 ;
}
exit:
F_8 ( V_11 ) ;
F_8 ( V_17 ) ;
return V_21 ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
int V_31 = V_22 ;
T_4 V_32 = 0 ;
if ( V_28 -> V_33 == NULL ) {
V_28 -> V_33 =
F_2 ( sizeof( struct V_34 ) , V_13 ) ;
if ( V_28 -> V_33 == NULL )
return - V_14 ;
}
if ( V_30 -> V_35 != sizeof( struct V_34 ) )
return - V_26 ;
V_31 = F_12 ( V_28 -> V_33 ,
V_30 -> V_36 ,
V_30 -> V_35 ) ;
if ( V_31 ) {
F_8 ( V_28 -> V_33 ) ;
V_28 -> V_33 = NULL ;
return - V_37 ;
}
F_13 ( V_28 ) ;
F_14 ( V_28 ) ;
V_31 = F_15 ( V_28 ) ;
if ( V_31 )
return V_31 ;
if ( V_28 -> V_38 . V_39 &
V_40 ) {
V_28 -> V_38 . V_41 = false ;
V_28 -> V_42 = V_43 ;
F_16 ( & V_28 -> V_38 . V_44 ) ;
}
if ( V_28 -> V_38 . V_39 &
V_40 ) {
V_28 -> V_42 = V_45 ;
F_16 ( & V_28 -> V_38 . V_44 ) ;
}
V_31 = F_17 ( V_28 ) ;
if ( V_31 )
return V_31 ;
V_32 = 0 ;
F_18 ( V_28 , V_46 - 4 ,
& V_32 , sizeof( V_32 ) ) ;
F_18 ( V_28 , V_46 - 8 ,
& V_32 , sizeof( V_32 ) ) ;
if ( V_28 -> V_47 == V_48 ) {
V_31 = F_19 ( V_28 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_20 ( V_28 , ( V_49 ) V_28 -> V_33 ,
sizeof( struct V_34 ) , V_25 ) ;
if ( V_31 )
F_21 ( V_28 , V_50 ,
V_51 , V_52 ,
L_1 ) ;
else
V_28 -> V_53 = TRUE ;
return V_31 ;
}
int F_22 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
int V_31 = V_22 ;
V_49 V_11 = NULL ;
F_23 ( & V_28 -> V_54 , false ) ;
if ( ! V_28 -> V_53 &&
V_30 -> V_55 != V_25 ) {
return - V_56 ;
}
if ( V_30 -> V_55 == V_25 ) {
V_31 = F_11 ( V_28 , V_30 ) ;
} else {
V_11 = F_24 ( V_30 -> V_35 , V_13 ) ;
if ( V_11 == NULL )
return - V_14 ;
V_31 = F_12 ( V_11 ,
V_30 -> V_36 ,
V_30 -> V_35 ) ;
if ( V_31 != V_22 ) {
V_31 = - V_37 ;
goto error;
}
V_31 = F_20 ( V_28 ,
V_11 ,
V_30 -> V_35 ,
V_30 -> V_55 ) ;
if ( V_31 != V_22 )
goto error;
}
error:
F_8 ( V_11 ) ;
return V_31 ;
}
static INT F_25 ( struct V_27 * V_28 ,
V_49 V_57 , T_5 V_35 ,
T_6 V_55 )
{
unsigned int V_7 = 0 ;
int V_31 = V_22 ;
V_7 = V_35 ;
while ( V_35 ) {
V_7 = F_26 ( V_35 , V_12 ) ;
V_31 = F_27 ( V_28 , V_55 , V_57 , V_7 ) ;
if ( V_31 )
break;
V_55 += V_7 ;
V_35 -= V_7 ;
V_57 += V_7 ;
}
return V_31 ;
}
static INT F_28 ( struct V_27 * V_28 ,
V_49 V_57 , T_5 V_35 ,
T_6 V_55 )
{
T_5 V_7 = V_35 ;
INT V_31 = V_22 ;
V_49 V_58 = F_24 ( V_12 , V_13 ) ;
int V_23 ;
if ( NULL == V_58 )
return - V_14 ;
while ( V_35 && ! V_31 ) {
V_7 = F_26 ( V_35 , V_12 ) ;
V_23 = F_29 ( V_28 , V_55 , V_58 , V_7 ) ;
if ( V_23 < 0 ) {
V_31 = V_23 ;
break;
}
if ( memcmp ( V_58 , V_57 , V_7 ) != 0 ) {
F_30 ( L_2 ,
V_59 ) ;
V_31 = - V_26 ;
}
V_55 += V_7 ;
V_35 -= V_7 ;
V_57 += V_7 ;
}
F_8 ( V_58 ) ;
return V_31 ;
}
INT F_20 ( struct V_27 * V_28 ,
unsigned char * V_57 ,
unsigned int V_35 ,
unsigned long V_55 )
{
INT V_60 = V_22 ;
V_60 = F_25 ( V_28 , V_57 ,
V_35 , V_55 ) ;
if ( V_60 != V_22 )
goto error;
V_60 = F_28 ( V_28 , V_57 ,
V_35 , V_55 ) ;
if ( V_60 != V_22 )
goto error;
error:
return V_60 ;
}
