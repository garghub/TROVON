int F_1 ( T_1 V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 ;
T_3 V_8 = 0 ;
T_4 V_9 = ( T_4 ) V_1 ;
char * V_10 = F_2 ( V_11 , V_12 ) ;
if ( ! V_10 )
return - V_13 ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_14 V_15 * ) V_10 ,
V_11 , & V_8 ) ;
F_4 ( V_5 ) ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 ) {
F_7 ( V_9 -> V_16 ,
V_17 , V_18 ,
V_19 , L_1 ) ;
V_6 = V_7 ;
} else {
V_6 = 0 ;
F_7 ( V_9 -> V_16 ,
V_17 , V_18 ,
V_19 ,
L_2 ) ;
}
break;
}
V_6 = F_8 ( V_9 , V_4 , V_10 , V_7 ) ;
if ( V_6 ) {
F_7 ( V_9 -> V_16 ,
V_20 , 0 , 0 ,
L_3 , V_6 ) ;
break;
}
V_4 += V_11 ;
}
F_9 ( V_10 ) ;
return V_6 ;
}
int F_10 ( T_1 V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
char * V_10 , * V_21 ;
unsigned int V_22 = 0 ;
T_2 V_5 = { 0 } ;
int V_6 = 0 , V_7 = 0 , V_23 = 0 ;
T_3 V_8 = 0 ;
static int V_24 ;
INT V_25 = V_26 ;
T_4 V_9 = ( T_4 ) V_1 ;
int V_27 ;
V_10 = F_2 ( V_11 , V_28 ) ;
V_21 = F_2 ( V_11 , V_28 ) ;
if ( ! V_10 || ! V_21 ) {
F_9 ( V_10 ) ;
F_9 ( V_21 ) ;
return - V_13 ;
}
V_23 = ( V_4 == V_29 ) ? 1 : 0 ;
memset ( V_21 , 0 , V_11 ) ;
memset ( V_10 , 0 , V_11 ) ;
while ( 1 ) {
V_5 = F_3 () ;
F_4 ( F_5 () ) ;
V_7 = F_6 ( V_3 , ( void V_14 V_15 * ) V_10 , V_11 , & V_8 ) ;
F_4 ( V_5 ) ;
V_24 ++ ;
if ( V_7 <= 0 ) {
if ( V_7 < 0 ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_1 ) ;
V_6 = V_7 ;
} else {
V_6 = 0 ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_2 ) ;
}
break;
}
V_27 = F_11 ( V_9 , V_4 , V_21 , V_7 ) ;
if ( V_27 < 0 ) {
V_25 = V_27 ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_4 , V_7 , V_22 ) ;
goto exit;
}
V_22 ++ ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_21 , V_10 , V_7 ) ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_5 , V_24 ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_6 , V_7 ) ;
V_25 = - V_30 ;
goto exit;
}
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_21 [ V_7 ] != * ( unsigned int * ) & V_10 [ V_7 ] ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_5 , V_24 ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_7 , * ( unsigned int * ) & V_10 [ V_7 ] , * ( unsigned int * ) & V_21 [ V_7 ] ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_8 , V_7 ) ;
V_25 = - V_30 ;
goto exit;
}
V_7 -= 4 ;
}
}
V_4 += V_11 ;
}
exit:
F_9 ( V_10 ) ;
F_9 ( V_21 ) ;
return V_25 ;
}
static int F_12 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_35 = V_26 ;
T_5 V_36 = 0 ;
if ( V_32 -> V_37 == NULL ) {
V_32 -> V_37 = F_2 ( sizeof( V_38 ) , V_12 ) ;
if ( V_32 -> V_37 == NULL )
return - V_13 ;
}
if ( V_34 -> V_39 != sizeof( V_38 ) )
return - V_30 ;
V_35 = F_13 ( V_32 -> V_37 , V_34 -> V_40 , V_34 -> V_39 ) ;
if ( V_35 ) {
F_9 ( V_32 -> V_37 ) ;
V_32 -> V_37 = NULL ;
return - V_41 ;
}
F_14 ( V_32 ) ;
F_15 ( V_32 ) ;
V_35 = F_16 ( V_32 ) ;
if ( V_35 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_9 ) ;
return V_35 ;
}
if ( V_32 -> V_42 . V_43 & V_44 ) {
V_32 -> V_42 . V_45 = FALSE ;
V_32 -> V_46 = V_47 ;
F_17 ( & V_32 -> V_42 . V_48 ) ;
}
if ( V_32 -> V_42 . V_43 & V_44 ) {
V_32 -> V_46 = V_49 ;
F_17 ( & V_32 -> V_42 . V_48 ) ;
}
V_35 = F_18 ( V_32 ) ;
if ( V_35 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_10 ) ;
return V_35 ;
}
V_36 = 0 ;
F_19 ( V_32 , V_50 - 4 , & V_36 , sizeof( V_36 ) ) ;
F_19 ( V_32 , V_50 - 8 , & V_36 , sizeof( V_36 ) ) ;
if ( V_32 -> V_51 == V_52 ) {
V_35 = F_20 ( V_32 ) ;
if ( V_35 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_11 , V_35 ) ;
return V_35 ;
}
}
V_35 = F_21 ( V_32 , ( V_53 ) V_32 -> V_37 , sizeof( V_38 ) , V_29 ) ;
if ( V_35 )
F_7 ( V_32 , V_17 , V_18 , V_19 , L_12 ) ;
else
V_32 -> V_54 = TRUE ;
return V_35 ;
}
static int F_22 ( unsigned char * V_55 , unsigned char * V_10 , unsigned int V_7 )
{
int V_35 = V_26 ;
struct V_31 * V_32 = F_23 ( V_56 ) ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_55 , V_10 , V_7 ) )
V_35 = - V_57 ;
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_55 [ V_7 ] != * ( unsigned int * ) & V_10 [ V_7 ] ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_13 ) ;
F_7 ( V_32 , V_17 , V_18 , V_19 , L_7 , * ( unsigned int * ) & V_10 [ V_7 ] , * ( unsigned int * ) & V_55 [ V_7 ] ) ;
F_7 ( V_32 , V_17 , V_18 , V_19 , L_8 , V_7 ) ;
V_35 = - V_57 ;
break;
}
V_7 -= 4 ;
}
}
return V_35 ;
}
int F_24 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_35 = V_26 ;
V_53 V_10 = NULL ;
F_25 ( & V_32 -> V_58 , FALSE ) ;
if ( ! V_32 -> V_54 && V_34 -> V_59 != V_29 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_14 ) ;
return - V_57 ;
}
if ( V_34 -> V_59 == V_29 ) {
V_35 = F_12 ( V_32 , V_34 ) ;
} else {
V_10 = F_26 ( V_34 -> V_39 , V_12 ) ;
if ( V_10 == NULL ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_15 ) ;
return - V_13 ;
}
V_35 = F_13 ( V_10 , V_34 -> V_40 , V_34 -> V_39 ) ;
if ( V_35 != V_26 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_16 ) ;
V_35 = - V_41 ;
goto error;
}
V_35 = F_21 ( V_32 ,
V_10 ,
V_34 -> V_39 ,
V_34 -> V_59 ) ;
if ( V_35 != V_26 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_17 , V_35 ) ;
goto error;
}
}
error:
F_9 ( V_10 ) ;
return V_35 ;
}
static INT F_27 ( struct V_31 * V_32 , V_53 V_60 , T_6 V_39 , T_7 V_59 )
{
unsigned int V_7 = 0 ;
int V_35 = V_26 ;
V_7 = V_39 ;
while ( V_39 ) {
V_7 = F_28 ( V_39 , V_11 ) ;
V_35 = F_29 ( V_32 , V_59 , V_60 , V_7 ) ;
if ( V_35 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_18 , V_35 ) ;
break;
}
V_59 += V_7 ;
V_39 -= V_7 ;
V_60 += V_7 ;
}
return V_35 ;
}
static INT F_30 ( struct V_31 * V_32 , V_53 V_60 , T_6 V_39 , T_7 V_59 )
{
T_6 V_7 = V_39 ;
INT V_35 = V_26 ;
V_53 V_55 = F_26 ( V_11 , V_12 ) ;
int V_27 ;
if ( NULL == V_55 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_19 ) ;
return - V_13 ;
}
while ( V_39 && ! V_35 ) {
V_7 = F_28 ( V_39 , V_11 ) ;
V_27 = F_31 ( V_32 , V_59 , V_55 , V_7 ) ;
if ( V_27 < 0 ) {
V_35 = V_27 ;
F_7 ( V_32 , V_17 , V_18 , V_19 , L_20 , V_35 ) ;
break;
}
V_35 = F_22 ( V_55 , V_60 , V_7 ) ;
if ( V_26 != V_35 )
break;
V_59 += V_7 ;
V_39 -= V_7 ;
V_60 += V_7 ;
}
F_9 ( V_55 ) ;
return V_35 ;
}
INT F_21 ( struct V_31 * V_32 , unsigned char * V_60 , unsigned int V_39 , unsigned long V_59 )
{
INT V_61 = V_26 ;
V_61 = F_27 ( V_32 , V_60 , V_39 , V_59 ) ;
if ( V_61 != V_26 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_21 ) ;
goto error;
}
V_61 = F_30 ( V_32 , V_60 , V_39 , V_59 ) ;
if ( V_61 != V_26 ) {
F_7 ( V_32 , V_17 , V_18 , V_19 , L_22 ) ;
goto error;
}
error:
return V_61 ;
}
