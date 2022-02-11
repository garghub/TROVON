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
V_10 = F_2 ( V_11 , V_27 ) ;
V_21 = F_2 ( V_11 , V_27 ) ;
if ( ! V_10 || ! V_21 ) {
F_9 ( V_10 ) ;
F_9 ( V_21 ) ;
return - V_13 ;
}
V_23 = ( V_4 == V_28 ) ? 1 : 0 ;
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
V_25 = F_11 ( V_9 , V_4 , V_21 , V_7 ) ;
if ( V_25 ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_4 , V_7 , V_22 ) ;
goto exit;
}
V_22 ++ ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_21 , V_10 , V_7 ) ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_5 , V_24 ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_6 , V_7 ) ;
V_25 = - V_29 ;
goto exit;
}
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_21 [ V_7 ] != * ( unsigned int * ) & V_10 [ V_7 ] ) {
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_5 , V_24 ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_7 , * ( unsigned int * ) & V_10 [ V_7 ] , * ( unsigned int * ) & V_21 [ V_7 ] ) ;
F_7 ( V_9 -> V_16 , V_17 , V_18 , V_19 , L_8 , V_7 ) ;
V_25 = - V_29 ;
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
static int F_12 ( T_5 V_30 , T_6 * V_31 )
{
int V_32 = V_26 ;
T_7 V_33 = 0 ;
if ( V_30 -> V_34 == NULL ) {
V_30 -> V_34 = F_2 ( sizeof( V_35 ) , V_12 ) ;
if ( V_30 -> V_34 == NULL )
return - V_13 ;
}
if ( V_31 -> V_36 != sizeof( V_35 ) )
return - V_29 ;
V_32 = F_13 ( V_30 -> V_34 , V_31 -> V_37 , V_31 -> V_36 ) ;
if ( V_32 ) {
F_9 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
return - V_38 ;
}
F_14 ( V_30 ) ;
F_15 ( V_30 ) ;
V_32 = F_16 ( V_30 ) ;
if ( V_32 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_9 ) ;
return V_32 ;
}
if ( V_30 -> V_39 . V_40 & V_41 ) {
V_30 -> V_39 . V_42 = FALSE ;
V_30 -> V_43 = V_44 ;
F_17 ( & V_30 -> V_39 . V_45 ) ;
}
if ( V_30 -> V_39 . V_40 & V_41 ) {
V_30 -> V_43 = V_46 ;
F_17 ( & V_30 -> V_39 . V_45 ) ;
}
V_32 = F_18 ( V_30 ) ;
if ( V_32 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_10 ) ;
return V_32 ;
}
V_33 = 0 ;
F_19 ( V_30 , V_47 - 4 , & V_33 , sizeof( V_33 ) ) ;
F_19 ( V_30 , V_47 - 8 , & V_33 , sizeof( V_33 ) ) ;
if ( V_30 -> V_48 == V_49 ) {
V_32 = F_20 ( V_30 ) ;
if ( V_32 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_11 , V_32 ) ;
return V_32 ;
}
}
V_32 = F_21 ( V_30 , ( V_50 ) V_30 -> V_34 , sizeof( V_35 ) , V_28 ) ;
if ( V_32 )
F_7 ( V_30 , V_17 , V_18 , V_19 , L_12 ) ;
else
V_30 -> V_51 = TRUE ;
return V_32 ;
}
static int F_22 ( unsigned char * V_52 , unsigned char * V_10 , unsigned int V_7 )
{
int V_32 = V_26 ;
T_5 V_30 = F_23 ( V_53 ) ;
if ( ( V_7 -sizeof( unsigned int ) ) < 4 ) {
if ( memcmp ( V_52 , V_10 , V_7 ) )
V_32 = - V_54 ;
} else {
V_7 -= 4 ;
while ( V_7 ) {
if ( * ( unsigned int * ) & V_52 [ V_7 ] != * ( unsigned int * ) & V_10 [ V_7 ] ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_13 ) ;
F_7 ( V_30 , V_17 , V_18 , V_19 , L_7 , * ( unsigned int * ) & V_10 [ V_7 ] , * ( unsigned int * ) & V_52 [ V_7 ] ) ;
F_7 ( V_30 , V_17 , V_18 , V_19 , L_8 , V_7 ) ;
V_32 = - V_54 ;
break;
}
V_7 -= 4 ;
}
}
return V_32 ;
}
int F_24 ( T_5 V_30 , T_6 * V_31 )
{
int V_32 = V_26 ;
V_50 V_10 = NULL ;
F_25 ( & V_30 -> V_55 , FALSE ) ;
if ( ! V_30 -> V_51 && V_31 -> V_56 != V_28 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_14 ) ;
return - V_54 ;
}
if ( V_31 -> V_56 == V_28 ) {
V_32 = F_12 ( V_30 , V_31 ) ;
} else {
V_10 = F_26 ( V_31 -> V_36 , V_12 ) ;
if ( V_10 == NULL ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_15 ) ;
return - V_13 ;
}
V_32 = F_13 ( V_10 , V_31 -> V_37 , V_31 -> V_36 ) ;
if ( V_32 != V_26 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_16 ) ;
V_32 = - V_38 ;
goto error;
}
V_32 = F_21 ( V_30 ,
V_10 ,
V_31 -> V_36 ,
V_31 -> V_56 ) ;
if ( V_32 != V_26 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_17 , V_32 ) ;
goto error;
}
}
error:
F_9 ( V_10 ) ;
return V_32 ;
}
static INT F_27 ( T_5 V_30 , V_50 V_57 , T_8 V_36 , T_9 V_56 )
{
unsigned int V_7 = 0 ;
int V_32 = V_26 ;
V_7 = V_36 ;
while ( V_36 ) {
V_7 = F_28 ( V_36 , V_11 ) ;
V_32 = F_29 ( V_30 , V_56 , V_57 , V_7 ) ;
if ( V_32 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_18 , V_32 ) ;
break;
}
V_56 += V_7 ;
V_36 -= V_7 ;
V_57 += V_7 ;
}
return V_32 ;
}
static INT F_30 ( T_5 V_30 , V_50 V_57 , T_8 V_36 , T_9 V_56 )
{
T_8 V_7 = V_36 ;
INT V_32 = V_26 ;
V_50 V_52 = F_26 ( V_11 , V_12 ) ;
if ( NULL == V_52 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_19 ) ;
return - V_13 ;
}
while ( V_36 && ! V_32 ) {
V_7 = F_28 ( V_36 , V_11 ) ;
V_32 = F_31 ( V_30 , V_56 , V_52 , V_7 ) ;
if ( V_32 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_20 , V_32 ) ;
break;
}
V_32 = F_22 ( V_52 , V_57 , V_7 ) ;
if ( V_26 != V_32 )
break;
V_56 += V_7 ;
V_36 -= V_7 ;
V_57 += V_7 ;
}
F_9 ( V_52 ) ;
return V_32 ;
}
INT F_21 ( T_5 V_30 , unsigned char * V_57 , unsigned int V_36 , unsigned long V_56 )
{
INT V_58 = V_26 ;
V_58 = F_27 ( V_30 , V_57 , V_36 , V_56 ) ;
if ( V_58 != V_26 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_21 ) ;
goto error;
}
V_58 = F_30 ( V_30 , V_57 , V_36 , V_56 ) ;
if ( V_58 != V_26 ) {
F_7 ( V_30 , V_17 , V_18 , V_19 , L_22 ) ;
goto error;
}
error:
return V_58 ;
}
