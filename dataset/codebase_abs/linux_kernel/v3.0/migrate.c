static int F_1 ( T_1 * V_1 , struct V_2 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 , V_6 ;
struct V_7 V_8 ;
struct V_9 * V_10 ;
if ( V_4 -> V_11 == 0 )
return 0 ;
V_8 . V_12 = F_2 ( V_4 -> V_13 ) ;
V_8 . V_14 = F_3 ( V_4 -> V_15 - V_4 -> V_13 + 1 ) ;
F_4 ( & V_8 , V_4 -> V_11 ) ;
V_10 = F_5 ( V_2 , V_4 -> V_13 , NULL ) ;
if ( F_6 ( V_10 ) ) {
V_5 = F_7 ( V_10 ) ;
V_10 = NULL ;
goto V_16;
}
V_6 = F_8 ( V_2 ,
V_4 -> V_15 - V_4 -> V_13 + 1 , V_10 ) ;
if ( V_6 && F_9 ( V_1 ,
V_17 ) ) {
V_5 = F_10 ( V_1 , V_6 ) ;
if ( V_5 )
goto V_16;
} else if ( V_6 ) {
V_5 = F_11 ( V_1 , V_6 ) ;
if ( V_5 ) {
V_5 = F_10 ( V_1 , V_6 ) ;
if ( V_5 )
goto V_16;
}
}
V_5 = F_12 ( V_1 , V_2 , V_10 , & V_8 , 0 ) ;
V_16:
if ( V_10 ) {
F_13 ( V_10 ) ;
F_14 ( V_10 ) ;
}
V_4 -> V_11 = 0 ;
return V_5 ;
}
static int F_15 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_18 , T_3 V_19 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_11 &&
( V_4 -> V_20 + 1 == V_18 ) &&
( V_4 -> V_15 + 1 == V_19 ) ) {
V_4 -> V_20 = V_18 ;
V_4 -> V_15 = V_19 ;
return 0 ;
}
V_5 = F_1 ( V_1 , V_2 , V_4 ) ;
V_4 -> V_11 = V_4 -> V_20 = V_18 ;
V_4 -> V_13 = V_4 -> V_15 = V_19 ;
return V_5 ;
}
static int F_16 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_18 , T_3 * V_21 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 ;
T_4 * V_24 ;
int V_25 , V_5 = 0 ;
T_3 V_26 = * V_21 ;
unsigned long V_27 = V_2 -> V_28 -> V_29 >> 2 ;
if ( ! V_18 ) {
* V_21 += V_27 ;
return 0 ;
}
V_23 = F_17 ( V_2 -> V_28 , V_18 ) ;
if ( ! V_23 )
return - V_30 ;
V_24 = ( T_4 * ) V_23 -> V_31 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ , V_26 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_15 ( V_1 , V_2 ,
F_18 ( V_24 [ V_25 ] ) ,
V_26 , V_4 ) ;
if ( V_5 )
break;
}
}
* V_21 = V_26 ;
F_19 ( V_23 ) ;
return V_5 ;
}
static int F_20 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_18 , T_3 * V_21 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 ;
T_4 * V_24 ;
int V_25 , V_5 = 0 ;
T_3 V_26 = * V_21 ;
unsigned long V_27 = V_2 -> V_28 -> V_29 >> 2 ;
if ( ! V_18 ) {
* V_21 += V_27 * V_27 ;
return 0 ;
}
V_23 = F_17 ( V_2 -> V_28 , V_18 ) ;
if ( ! V_23 )
return - V_30 ;
V_24 = ( T_4 * ) V_23 -> V_31 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_16 ( V_1 , V_2 ,
F_18 ( V_24 [ V_25 ] ) ,
& V_26 , V_4 ) ;
if ( V_5 )
break;
} else {
V_26 += V_27 ;
}
}
* V_21 = V_26 ;
F_19 ( V_23 ) ;
return V_5 ;
}
static int F_21 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_18 , T_3 * V_21 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 ;
T_4 * V_24 ;
int V_25 , V_5 = 0 ;
T_3 V_26 = * V_21 ;
unsigned long V_27 = V_2 -> V_28 -> V_29 >> 2 ;
if ( ! V_18 ) {
* V_21 += V_27 * V_27 * V_27 ;
return 0 ;
}
V_23 = F_17 ( V_2 -> V_28 , V_18 ) ;
if ( ! V_23 )
return - V_30 ;
V_24 = ( T_4 * ) V_23 -> V_31 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_20 ( V_1 , V_2 ,
F_18 ( V_24 [ V_25 ] ) ,
& V_26 , V_4 ) ;
if ( V_5 )
break;
} else
V_26 += V_27 * V_27 ;
}
* V_21 = V_26 ;
F_19 ( V_23 ) ;
return V_5 ;
}
static int F_22 ( T_1 * V_1 , struct V_2 * V_2 )
{
int V_5 = 0 , V_6 ;
if ( F_9 ( V_1 , V_17 + 1 ) )
return 0 ;
V_6 = 3 + F_23 ( V_2 -> V_28 ) ;
if ( F_11 ( V_1 , V_6 ) != 0 )
V_5 = F_10 ( V_1 , V_6 ) ;
return V_5 ;
}
static int F_24 ( T_1 * V_1 ,
struct V_2 * V_2 , T_4 V_24 )
{
int V_25 ;
T_4 * V_32 ;
struct V_22 * V_23 ;
unsigned long V_27 = V_2 -> V_28 -> V_29 >> 2 ;
V_23 = F_17 ( V_2 -> V_28 , F_18 ( V_24 ) ) ;
if ( ! V_23 )
return - V_30 ;
V_32 = ( T_4 * ) V_23 -> V_31 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
if ( V_32 [ V_25 ] ) {
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL ,
F_18 ( V_32 [ V_25 ] ) , 1 ,
V_33 |
V_34 ) ;
}
}
F_19 ( V_23 ) ;
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL , F_18 ( V_24 ) , 1 ,
V_33 |
V_34 ) ;
return 0 ;
}
static int F_26 ( T_1 * V_1 ,
struct V_2 * V_2 , T_4 V_24 )
{
int V_25 , V_5 = 0 ;
T_4 * V_32 ;
struct V_22 * V_23 ;
unsigned long V_27 = V_2 -> V_28 -> V_29 >> 2 ;
V_23 = F_17 ( V_2 -> V_28 , F_18 ( V_24 ) ) ;
if ( ! V_23 )
return - V_30 ;
V_32 = ( T_4 * ) V_23 -> V_31 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
if ( V_32 [ V_25 ] ) {
V_5 = F_24 ( V_1 ,
V_2 , V_32 [ V_25 ] ) ;
if ( V_5 ) {
F_19 ( V_23 ) ;
return V_5 ;
}
}
}
F_19 ( V_23 ) ;
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL , F_18 ( V_24 ) , 1 ,
V_33 |
V_34 ) ;
return 0 ;
}
static int F_27 ( T_1 * V_1 , struct V_2 * V_2 , T_4 * V_24 )
{
int V_5 ;
if ( V_24 [ 0 ] ) {
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL ,
F_18 ( V_24 [ 0 ] ) , 1 ,
V_33 |
V_34 ) ;
}
if ( V_24 [ 1 ] ) {
V_5 = F_24 ( V_1 , V_2 , V_24 [ 1 ] ) ;
if ( V_5 )
return V_5 ;
}
if ( V_24 [ 2 ] ) {
V_5 = F_26 ( V_1 , V_2 , V_24 [ 2 ] ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_28 ( T_1 * V_1 , struct V_2 * V_2 ,
struct V_2 * V_35 )
{
int V_5 ;
T_4 V_24 [ 3 ] ;
struct V_36 * V_37 = F_29 ( V_2 ) ;
struct V_36 * V_38 = F_29 ( V_35 ) ;
V_5 = F_11 ( V_1 , 1 ) ;
if ( V_5 ) {
V_5 = F_10 ( V_1 , 1 ) ;
if ( V_5 )
goto V_16;
}
V_24 [ 0 ] = V_37 -> V_24 [ V_39 ] ;
V_24 [ 1 ] = V_37 -> V_24 [ V_40 ] ;
V_24 [ 2 ] = V_37 -> V_24 [ V_41 ] ;
F_30 ( & F_29 ( V_2 ) -> V_42 ) ;
if ( ! F_31 ( V_2 , V_43 ) ) {
V_5 = - V_44 ;
F_32 ( & F_29 ( V_2 ) -> V_42 ) ;
goto V_16;
} else
F_33 ( V_2 , V_43 ) ;
F_34 ( V_2 , V_45 ) ;
memcpy ( V_37 -> V_24 , V_38 -> V_24 , sizeof( V_37 -> V_24 ) ) ;
F_35 ( & V_2 -> V_46 ) ;
V_2 -> V_47 += V_35 -> V_47 ;
F_36 ( & V_2 -> V_46 ) ;
F_32 ( & F_29 ( V_2 ) -> V_42 ) ;
V_5 = F_27 ( V_1 , V_2 , V_24 ) ;
F_37 ( V_1 , V_2 ) ;
V_16:
return V_5 ;
}
static int F_38 ( T_1 * V_1 , struct V_2 * V_2 ,
struct V_48 * V_49 )
{
int V_25 , V_5 = 0 ;
T_2 V_50 ;
struct V_22 * V_23 ;
struct V_51 * V_52 ;
V_50 = F_39 ( V_49 ) ;
V_23 = F_17 ( V_2 -> V_28 , V_50 ) ;
if ( ! V_23 )
return - V_30 ;
V_52 = (struct V_51 * ) V_23 -> V_31 ;
if ( V_52 -> V_53 != 0 ) {
V_49 = F_40 ( V_52 ) ;
for ( V_25 = 0 ; V_25 < F_41 ( V_52 -> V_54 ) ; V_25 ++ , V_49 ++ ) {
V_5 = F_38 ( V_1 , V_2 , V_49 ) ;
if ( V_5 )
break;
}
}
F_19 ( V_23 ) ;
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL , V_50 , 1 ,
V_33 | V_34 ) ;
return V_5 ;
}
static int F_42 ( T_1 * V_1 , struct V_2 * V_2 )
{
int V_25 , V_5 = 0 ;
struct V_36 * V_37 = F_29 ( V_2 ) ;
struct V_51 * V_52 = (struct V_51 * ) V_37 -> V_24 ;
struct V_48 * V_49 ;
if ( V_52 -> V_53 == 0 )
return 0 ;
V_49 = F_40 ( V_52 ) ;
for ( V_25 = 0 ; V_25 < F_41 ( V_52 -> V_54 ) ; V_25 ++ , V_49 ++ ) {
V_5 = F_38 ( V_1 , V_2 , V_49 ) ;
if ( V_5 )
return V_5 ;
}
return V_5 ;
}
int F_43 ( struct V_2 * V_2 )
{
T_1 * V_1 ;
int V_5 = 0 , V_25 ;
T_4 * V_24 ;
T_3 V_26 = 0 ;
struct V_36 * V_37 ;
struct V_2 * V_35 = NULL ;
struct V_3 V_4 ;
unsigned long V_27 ;
T_5 V_55 ;
if ( ! F_44 ( V_2 -> V_28 ,
V_56 ) ||
( F_45 ( V_2 , V_45 ) ) )
return - V_57 ;
if ( F_46 ( V_2 -> V_58 ) && V_2 -> V_47 == 0 )
return V_5 ;
V_1 = F_47 ( V_2 ,
F_48 ( V_2 -> V_28 ) +
V_59 + 3 +
F_49 ( V_2 -> V_28 )
+ 1 ) ;
if ( F_6 ( V_1 ) ) {
V_5 = F_7 ( V_1 ) ;
return V_5 ;
}
V_55 = ( ( ( V_2 -> V_60 - 1 ) / F_50 ( V_2 -> V_28 ) ) *
F_50 ( V_2 -> V_28 ) ) + 1 ;
V_35 = F_51 ( V_1 , V_2 -> V_28 -> V_61 -> V_62 ,
V_63 , NULL , V_55 ) ;
if ( F_6 ( V_35 ) ) {
V_5 = - V_64 ;
F_52 ( V_1 ) ;
return V_5 ;
}
F_53 ( V_35 , F_54 ( V_2 ) ) ;
V_35 -> V_65 = 0 ;
F_55 ( V_1 , V_35 ) ;
F_56 ( V_1 , V_35 ) ;
F_52 ( V_1 ) ;
F_57 ( ( & F_29 ( V_2 ) -> V_42 ) ) ;
F_58 ( V_2 , V_43 ) ;
F_59 ( ( & F_29 ( V_2 ) -> V_42 ) ) ;
V_1 = F_47 ( V_2 , 1 ) ;
if ( F_6 ( V_1 ) ) {
F_60 ( NULL , V_35 ) ;
V_5 = F_7 ( V_1 ) ;
goto V_66;
}
V_37 = F_29 ( V_2 ) ;
V_24 = V_37 -> V_24 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_27 = V_2 -> V_28 -> V_29 >> 2 ;
for ( V_25 = 0 ; V_25 < V_67 ; V_25 ++ , V_26 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_15 ( V_1 , V_35 ,
F_18 ( V_24 [ V_25 ] ) ,
V_26 , & V_4 ) ;
if ( V_5 )
goto V_16;
}
}
if ( V_24 [ V_39 ] ) {
V_5 = F_16 ( V_1 , V_35 ,
F_18 ( V_24 [ V_39 ] ) ,
& V_26 , & V_4 ) ;
if ( V_5 )
goto V_16;
} else
V_26 += V_27 ;
if ( V_24 [ V_40 ] ) {
V_5 = F_20 ( V_1 , V_35 ,
F_18 ( V_24 [ V_40 ] ) ,
& V_26 , & V_4 ) ;
if ( V_5 )
goto V_16;
} else
V_26 += V_27 * V_27 ;
if ( V_24 [ V_41 ] ) {
V_5 = F_21 ( V_1 , V_35 ,
F_18 ( V_24 [ V_41 ] ) ,
& V_26 , & V_4 ) ;
if ( V_5 )
goto V_16;
}
V_5 = F_1 ( V_1 , V_35 , & V_4 ) ;
V_16:
if ( V_5 )
F_42 ( V_1 , V_35 ) ;
else {
V_5 = F_28 ( V_1 , V_2 , V_35 ) ;
if ( V_5 )
F_42 ( V_1 , V_35 ) ;
}
if ( F_11 ( V_1 , 1 ) != 0 )
F_10 ( V_1 , 1 ) ;
F_53 ( V_35 , 0 ) ;
V_35 -> V_47 = 0 ;
F_55 ( V_1 , V_35 ) ;
F_52 ( V_1 ) ;
V_66:
F_61 ( V_35 ) ;
F_62 ( V_35 ) ;
return V_5 ;
}
