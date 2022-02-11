static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 = F_2 ( V_3 ,
V_1 , 0 ) ;
if ( V_2 . V_4 . V_5 > V_6 )
V_2 . V_4 . V_5 = V_6 ;
F_3 ( V_1 > V_7 ) ;
return V_2 ;
}
static void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_10 = F_5 ( V_9 , struct V_10 , V_11 ) ;
F_6 ( V_10 -> V_12 ) ;
F_7 ( V_10 -> V_13 ) ;
F_7 ( V_10 ) ;
}
static struct V_8 * F_8 ( void )
{
T_1 V_2 =
F_1 ( V_7 ) ;
struct V_10 * V_10 ;
V_10 = F_9 ( sizeof( * V_10 ) , V_14 ) ;
if ( ! V_10 )
return F_10 ( - V_15 ) ;
V_10 -> V_16 = F_11 ( T_2 ,
F_12 ( V_2 . V_4 ) ,
F_13 ( V_7 ) ) ;
V_10 -> V_12 = F_14 ( V_10 -> V_16 , V_14 ) ;
V_10 -> V_13 = F_15 ( V_17 , V_14 ) ;
if ( ! V_10 -> V_12 || ! V_10 -> V_13 )
goto V_18;
F_16 ( & V_10 -> V_11 ) ;
return & V_10 -> V_11 ;
V_18:
F_4 ( & V_10 -> V_11 ) ;
return F_10 ( - V_15 ) ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_19 * V_20 ,
T_3 V_21 ,
struct V_22 * * V_23 ,
unsigned long * V_24 ,
unsigned long * V_25 ,
unsigned long * V_26 )
{
struct V_10 * V_10 = F_5 ( V_9 , struct V_10 , V_11 ) ;
T_4 * V_27 ;
int V_28 = 0 ;
int V_29 = 0 ;
struct V_22 * V_30 = NULL ;
struct V_22 * V_31 = NULL ;
T_5 V_32 = { NULL , 0 , 0 } ;
T_6 V_33 = { NULL , 0 , 0 } ;
unsigned long V_34 = 0 ;
unsigned long V_35 = 0 ;
unsigned long V_36 = * V_26 ;
const unsigned long V_37 = * V_24 ;
unsigned long V_38 = V_37 * V_17 ;
T_1 V_2 = F_1 ( V_36 ) ;
* V_24 = 0 ;
* V_26 = 0 ;
* V_25 = 0 ;
V_27 = F_18 ( V_2 , V_36 , V_10 -> V_12 ,
V_10 -> V_16 ) ;
if ( ! V_27 ) {
F_19 ( L_1 ) ;
V_28 = - V_39 ;
goto V_40;
}
V_30 = F_20 ( V_20 , V_21 >> V_41 ) ;
V_32 . V_42 = F_21 ( V_30 ) ;
V_32 . V_43 = 0 ;
V_32 . V_16 = F_22 ( T_2 , V_36 , V_17 ) ;
V_31 = F_23 ( V_44 | V_45 ) ;
if ( V_31 == NULL ) {
V_28 = - V_15 ;
goto V_40;
}
V_23 [ V_29 ++ ] = V_31 ;
V_33 . V_46 = F_21 ( V_31 ) ;
V_33 . V_43 = 0 ;
V_33 . V_16 = F_22 ( T_2 , V_38 , V_17 ) ;
while ( 1 ) {
T_2 V_47 ;
V_47 = F_24 ( V_27 , & V_33 , & V_32 ) ;
if ( F_25 ( V_47 ) ) {
F_26 ( L_2 ,
F_27 ( V_47 ) ) ;
V_28 = - V_39 ;
goto V_40;
}
if ( V_34 + V_32 . V_43 > 8192 &&
V_34 + V_32 . V_43 <
V_35 + V_33 . V_43 ) {
V_28 = - V_48 ;
goto V_40;
}
if ( V_33 . V_43 >= V_38 ) {
V_35 += V_33 . V_43 ;
V_28 = - V_48 ;
goto V_40;
}
if ( V_33 . V_43 == V_33 . V_16 ) {
V_35 += V_17 ;
V_38 -= V_17 ;
F_28 ( V_31 ) ;
if ( V_29 == V_37 ) {
V_31 = NULL ;
V_28 = - V_48 ;
goto V_40;
}
V_31 = F_23 ( V_44 | V_45 ) ;
if ( V_31 == NULL ) {
V_28 = - V_15 ;
goto V_40;
}
V_23 [ V_29 ++ ] = V_31 ;
V_33 . V_46 = F_21 ( V_31 ) ;
V_33 . V_43 = 0 ;
V_33 . V_16 = F_22 ( T_2 , V_38 , V_17 ) ;
}
if ( V_32 . V_43 >= V_36 ) {
V_34 += V_32 . V_43 ;
break;
}
if ( V_32 . V_43 == V_32 . V_16 ) {
V_34 += V_17 ;
F_28 ( V_30 ) ;
F_29 ( V_30 ) ;
V_21 += V_17 ;
V_36 -= V_17 ;
V_30 = F_20 ( V_20 , V_21 >> V_41 ) ;
V_32 . V_42 = F_21 ( V_30 ) ;
V_32 . V_43 = 0 ;
V_32 . V_16 = F_22 ( T_2 , V_36 , V_17 ) ;
}
}
while ( 1 ) {
T_2 V_47 ;
V_47 = F_30 ( V_27 , & V_33 ) ;
if ( F_25 ( V_47 ) ) {
F_26 ( L_3 ,
F_27 ( V_47 ) ) ;
V_28 = - V_39 ;
goto V_40;
}
if ( V_47 == 0 ) {
V_35 += V_33 . V_43 ;
break;
}
if ( V_33 . V_43 >= V_38 ) {
V_35 += V_33 . V_43 ;
V_28 = - V_48 ;
goto V_40;
}
V_35 += V_17 ;
V_38 -= V_17 ;
F_28 ( V_31 ) ;
if ( V_29 == V_37 ) {
V_31 = NULL ;
V_28 = - V_48 ;
goto V_40;
}
V_31 = F_23 ( V_44 | V_45 ) ;
if ( V_31 == NULL ) {
V_28 = - V_15 ;
goto V_40;
}
V_23 [ V_29 ++ ] = V_31 ;
V_33 . V_46 = F_21 ( V_31 ) ;
V_33 . V_43 = 0 ;
V_33 . V_16 = F_22 ( T_2 , V_38 , V_17 ) ;
}
if ( V_35 >= V_34 ) {
V_28 = - V_48 ;
goto V_40;
}
V_28 = 0 ;
* V_25 = V_34 ;
* V_26 = V_35 ;
V_40:
* V_24 = V_29 ;
if ( V_30 ) {
F_28 ( V_30 ) ;
F_29 ( V_30 ) ;
}
if ( V_31 )
F_28 ( V_31 ) ;
return V_28 ;
}
static int F_31 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_10 * V_10 = F_5 ( V_9 , struct V_10 , V_11 ) ;
struct V_22 * * V_51 = V_50 -> V_52 ;
T_3 V_53 = V_50 -> V_21 ;
struct V_54 * V_55 = V_50 -> V_55 ;
T_2 V_56 = V_50 -> V_57 ;
T_7 * V_27 ;
int V_28 = 0 ;
unsigned long V_58 = 0 ;
unsigned long V_59 = F_32 ( V_56 , V_17 ) ;
unsigned long V_60 ;
unsigned long V_26 = 0 ;
T_5 V_32 = { NULL , 0 , 0 } ;
T_6 V_33 = { NULL , 0 , 0 } ;
V_27 = F_33 (
V_7 , V_10 -> V_12 , V_10 -> V_16 ) ;
if ( ! V_27 ) {
F_26 ( L_4 ) ;
V_28 = - V_39 ;
goto V_61;
}
V_32 . V_42 = F_21 ( V_51 [ V_58 ] ) ;
V_32 . V_43 = 0 ;
V_32 . V_16 = F_22 ( T_2 , V_56 , V_17 ) ;
V_33 . V_46 = V_10 -> V_13 ;
V_33 . V_43 = 0 ;
V_33 . V_16 = V_17 ;
while ( 1 ) {
T_2 V_47 ;
V_47 = F_34 ( V_27 , & V_33 , & V_32 ) ;
if ( F_25 ( V_47 ) ) {
F_26 ( L_5 ,
F_27 ( V_47 ) ) ;
V_28 = - V_39 ;
goto V_61;
}
V_60 = V_26 ;
V_26 += V_33 . V_43 ;
V_33 . V_43 = 0 ;
V_28 = F_35 ( V_33 . V_46 , V_60 ,
V_26 , V_53 , V_55 ) ;
if ( V_28 == 0 )
break;
if ( V_32 . V_43 >= V_56 )
break;
if ( V_47 == 0 )
break;
if ( V_32 . V_43 == V_32 . V_16 ) {
F_28 ( V_51 [ V_58 ++ ] ) ;
if ( V_58 >= V_59 ) {
V_32 . V_42 = NULL ;
V_28 = - V_39 ;
goto V_61;
}
V_56 -= V_17 ;
V_32 . V_42 = F_21 ( V_51 [ V_58 ] ) ;
V_32 . V_43 = 0 ;
V_32 . V_16 = F_22 ( T_2 , V_56 , V_17 ) ;
}
}
V_28 = 0 ;
F_36 ( V_55 ) ;
V_61:
if ( V_32 . V_42 )
F_28 ( V_51 [ V_58 ] ) ;
return V_28 ;
}
static int F_37 ( struct V_8 * V_9 , unsigned char * V_62 ,
struct V_22 * V_63 ,
unsigned long V_64 ,
T_2 V_56 , T_2 V_65 )
{
struct V_10 * V_10 = F_5 ( V_9 , struct V_10 , V_11 ) ;
T_7 * V_27 ;
int V_28 = 0 ;
T_2 V_47 ;
T_5 V_32 = { NULL , 0 , 0 } ;
T_6 V_33 = { NULL , 0 , 0 } ;
unsigned long V_26 = 0 ;
unsigned long V_66 = 0 ;
char * V_67 ;
V_27 = F_33 (
V_7 , V_10 -> V_12 , V_10 -> V_16 ) ;
if ( ! V_27 ) {
F_19 ( L_4 ) ;
V_28 = - V_39 ;
goto V_68;
}
V_65 = F_22 ( T_2 , V_65 , V_17 ) ;
V_32 . V_42 = V_62 ;
V_32 . V_43 = 0 ;
V_32 . V_16 = V_56 ;
V_33 . V_46 = V_10 -> V_13 ;
V_33 . V_43 = 0 ;
V_33 . V_16 = V_17 ;
V_47 = 1 ;
while ( V_66 < V_65 && V_32 . V_43 < V_32 . V_16 ) {
unsigned long V_60 ;
unsigned long V_69 ;
unsigned long V_70 ;
if ( V_47 == 0 ) {
F_26 ( L_6 ) ;
V_28 = - V_39 ;
goto V_68;
}
V_47 = F_34 ( V_27 , & V_33 , & V_32 ) ;
if ( F_25 ( V_47 ) ) {
F_26 ( L_5 ,
F_27 ( V_47 ) ) ;
V_28 = - V_39 ;
goto V_68;
}
V_60 = V_26 ;
V_26 += V_33 . V_43 ;
V_33 . V_43 = 0 ;
if ( V_26 <= V_64 )
continue;
if ( V_26 > V_64 && V_60 < V_64 )
V_69 = V_64 - V_60 ;
else
V_69 = 0 ;
V_70 = F_22 (unsigned long, destlen - pg_offset,
out_buf.size - buf_offset) ;
V_67 = F_38 ( V_63 ) ;
memcpy ( V_67 + V_66 , V_33 . V_46 + V_69 , V_70 ) ;
F_39 ( V_67 ) ;
V_66 += V_70 ;
}
V_28 = 0 ;
V_68:
if ( V_66 < V_65 ) {
V_67 = F_38 ( V_63 ) ;
memset ( V_67 + V_66 , 0 , V_65 - V_66 ) ;
F_39 ( V_67 ) ;
}
return V_28 ;
}
