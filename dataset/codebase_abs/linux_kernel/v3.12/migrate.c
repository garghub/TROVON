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
V_10 = F_5 ( V_2 , V_4 -> V_13 , NULL , 0 ) ;
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
T_2 V_18 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_11 &&
( V_4 -> V_19 + 1 == V_18 ) &&
( V_4 -> V_15 + 1 == V_4 -> V_20 ) ) {
V_4 -> V_19 = V_18 ;
V_4 -> V_15 = V_4 -> V_20 ;
V_4 -> V_20 ++ ;
return 0 ;
}
V_5 = F_1 ( V_1 , V_2 , V_4 ) ;
V_4 -> V_11 = V_4 -> V_19 = V_18 ;
V_4 -> V_13 = V_4 -> V_15 = V_4 -> V_20 ;
V_4 -> V_20 ++ ;
return V_5 ;
}
static int F_16 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_18 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 ;
T_3 * V_23 ;
int V_24 , V_5 = 0 ;
unsigned long V_25 = V_2 -> V_26 -> V_27 >> 2 ;
V_22 = F_17 ( V_2 -> V_26 , V_18 ) ;
if ( ! V_22 )
return - V_28 ;
V_23 = ( T_3 * ) V_22 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_23 [ V_24 ] ) {
V_5 = F_15 ( V_1 , V_2 ,
F_18 ( V_23 [ V_24 ] ) , V_4 ) ;
if ( V_5 )
break;
} else {
V_4 -> V_20 ++ ;
}
}
F_19 ( V_22 ) ;
return V_5 ;
}
static int F_20 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_18 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 ;
T_3 * V_23 ;
int V_24 , V_5 = 0 ;
unsigned long V_25 = V_2 -> V_26 -> V_27 >> 2 ;
V_22 = F_17 ( V_2 -> V_26 , V_18 ) ;
if ( ! V_22 )
return - V_28 ;
V_23 = ( T_3 * ) V_22 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_23 [ V_24 ] ) {
V_5 = F_16 ( V_1 , V_2 ,
F_18 ( V_23 [ V_24 ] ) , V_4 ) ;
if ( V_5 )
break;
} else {
V_4 -> V_20 += V_25 ;
}
}
F_19 ( V_22 ) ;
return V_5 ;
}
static int F_21 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_18 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 ;
T_3 * V_23 ;
int V_24 , V_5 = 0 ;
unsigned long V_25 = V_2 -> V_26 -> V_27 >> 2 ;
V_22 = F_17 ( V_2 -> V_26 , V_18 ) ;
if ( ! V_22 )
return - V_28 ;
V_23 = ( T_3 * ) V_22 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_23 [ V_24 ] ) {
V_5 = F_20 ( V_1 , V_2 ,
F_18 ( V_23 [ V_24 ] ) , V_4 ) ;
if ( V_5 )
break;
} else {
V_4 -> V_20 += V_25 * V_25 ;
}
}
F_19 ( V_22 ) ;
return V_5 ;
}
static int F_22 ( T_1 * V_1 , struct V_2 * V_2 )
{
int V_5 = 0 , V_6 ;
if ( F_9 ( V_1 , V_17 + 1 ) )
return 0 ;
V_6 = 3 + F_23 ( V_2 -> V_26 ) ;
if ( F_11 ( V_1 , V_6 ) != 0 )
V_5 = F_10 ( V_1 , V_6 ) ;
return V_5 ;
}
static int F_24 ( T_1 * V_1 ,
struct V_2 * V_2 , T_3 V_23 )
{
int V_24 ;
T_3 * V_30 ;
struct V_21 * V_22 ;
unsigned long V_25 = V_2 -> V_26 -> V_27 >> 2 ;
V_22 = F_17 ( V_2 -> V_26 , F_18 ( V_23 ) ) ;
if ( ! V_22 )
return - V_28 ;
V_30 = ( T_3 * ) V_22 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_30 [ V_24 ] ) {
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL ,
F_18 ( V_30 [ V_24 ] ) , 1 ,
V_31 |
V_32 ) ;
}
}
F_19 ( V_22 ) ;
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL , F_18 ( V_23 ) , 1 ,
V_31 |
V_32 ) ;
return 0 ;
}
static int F_26 ( T_1 * V_1 ,
struct V_2 * V_2 , T_3 V_23 )
{
int V_24 , V_5 = 0 ;
T_3 * V_30 ;
struct V_21 * V_22 ;
unsigned long V_25 = V_2 -> V_26 -> V_27 >> 2 ;
V_22 = F_17 ( V_2 -> V_26 , F_18 ( V_23 ) ) ;
if ( ! V_22 )
return - V_28 ;
V_30 = ( T_3 * ) V_22 -> V_29 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
if ( V_30 [ V_24 ] ) {
V_5 = F_24 ( V_1 ,
V_2 , V_30 [ V_24 ] ) ;
if ( V_5 ) {
F_19 ( V_22 ) ;
return V_5 ;
}
}
}
F_19 ( V_22 ) ;
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL , F_18 ( V_23 ) , 1 ,
V_31 |
V_32 ) ;
return 0 ;
}
static int F_27 ( T_1 * V_1 , struct V_2 * V_2 , T_3 * V_23 )
{
int V_5 ;
if ( V_23 [ 0 ] ) {
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL ,
F_18 ( V_23 [ 0 ] ) , 1 ,
V_31 |
V_32 ) ;
}
if ( V_23 [ 1 ] ) {
V_5 = F_24 ( V_1 , V_2 , V_23 [ 1 ] ) ;
if ( V_5 )
return V_5 ;
}
if ( V_23 [ 2 ] ) {
V_5 = F_26 ( V_1 , V_2 , V_23 [ 2 ] ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_28 ( T_1 * V_1 , struct V_2 * V_2 ,
struct V_2 * V_33 )
{
int V_5 ;
T_3 V_23 [ 3 ] ;
struct V_34 * V_35 = F_29 ( V_2 ) ;
struct V_34 * V_36 = F_29 ( V_33 ) ;
V_5 = F_11 ( V_1 , 1 ) ;
if ( V_5 ) {
V_5 = F_10 ( V_1 , 1 ) ;
if ( V_5 )
goto V_16;
}
V_23 [ 0 ] = V_35 -> V_23 [ V_37 ] ;
V_23 [ 1 ] = V_35 -> V_23 [ V_38 ] ;
V_23 [ 2 ] = V_35 -> V_23 [ V_39 ] ;
F_30 ( & F_29 ( V_2 ) -> V_40 ) ;
if ( ! F_31 ( V_2 , V_41 ) ) {
V_5 = - V_42 ;
F_32 ( & F_29 ( V_2 ) -> V_40 ) ;
goto V_16;
} else
F_33 ( V_2 , V_41 ) ;
F_34 ( V_2 , V_43 ) ;
memcpy ( V_35 -> V_23 , V_36 -> V_23 , sizeof( V_35 -> V_23 ) ) ;
F_35 ( & V_2 -> V_44 ) ;
V_2 -> V_45 += V_33 -> V_45 ;
F_36 ( & V_2 -> V_44 ) ;
F_32 ( & F_29 ( V_2 ) -> V_40 ) ;
V_5 = F_27 ( V_1 , V_2 , V_23 ) ;
F_37 ( V_1 , V_2 ) ;
V_16:
return V_5 ;
}
static int F_38 ( T_1 * V_1 , struct V_2 * V_2 ,
struct V_46 * V_47 )
{
int V_24 , V_5 = 0 ;
T_2 V_48 ;
struct V_21 * V_22 ;
struct V_49 * V_50 ;
V_48 = F_39 ( V_47 ) ;
V_22 = F_17 ( V_2 -> V_26 , V_48 ) ;
if ( ! V_22 )
return - V_28 ;
V_50 = (struct V_49 * ) V_22 -> V_29 ;
if ( V_50 -> V_51 != 0 ) {
V_47 = F_40 ( V_50 ) ;
for ( V_24 = 0 ; V_24 < F_41 ( V_50 -> V_52 ) ; V_24 ++ , V_47 ++ ) {
V_5 = F_38 ( V_1 , V_2 , V_47 ) ;
if ( V_5 )
break;
}
}
F_19 ( V_22 ) ;
F_22 ( V_1 , V_2 ) ;
F_25 ( V_1 , V_2 , NULL , V_48 , 1 ,
V_31 | V_32 ) ;
return V_5 ;
}
static int F_42 ( T_1 * V_1 , struct V_2 * V_2 )
{
int V_24 , V_5 = 0 ;
struct V_34 * V_35 = F_29 ( V_2 ) ;
struct V_49 * V_50 = (struct V_49 * ) V_35 -> V_23 ;
struct V_46 * V_47 ;
if ( V_50 -> V_51 == 0 )
return 0 ;
V_47 = F_40 ( V_50 ) ;
for ( V_24 = 0 ; V_24 < F_41 ( V_50 -> V_52 ) ; V_24 ++ , V_47 ++ ) {
V_5 = F_38 ( V_1 , V_2 , V_47 ) ;
if ( V_5 )
return V_5 ;
}
return V_5 ;
}
int F_43 ( struct V_2 * V_2 )
{
T_1 * V_1 ;
int V_5 = 0 , V_24 ;
T_3 * V_23 ;
struct V_34 * V_35 ;
struct V_2 * V_33 = NULL ;
struct V_3 V_4 ;
unsigned long V_25 ;
T_4 V_53 ;
T_5 V_54 [ 2 ] ;
if ( ! F_44 ( V_2 -> V_26 ,
V_55 ) ||
( F_45 ( V_2 , V_43 ) ) )
return - V_56 ;
if ( F_46 ( V_2 -> V_57 ) && V_2 -> V_45 == 0 )
return V_5 ;
V_1 = F_47 ( V_2 , V_58 ,
4 + F_23 ( V_2 -> V_26 ) ) ;
if ( F_6 ( V_1 ) ) {
V_5 = F_7 ( V_1 ) ;
return V_5 ;
}
V_53 = ( ( ( V_2 -> V_59 - 1 ) / F_48 ( V_2 -> V_26 ) ) *
F_48 ( V_2 -> V_26 ) ) + 1 ;
V_54 [ 0 ] = F_49 ( V_2 ) ;
V_54 [ 1 ] = F_50 ( V_2 ) ;
V_33 = F_51 ( V_1 , V_2 -> V_26 -> V_60 -> V_61 ,
V_62 , NULL , V_53 , V_54 ) ;
if ( F_6 ( V_33 ) ) {
V_5 = F_7 ( V_33 ) ;
F_52 ( V_1 ) ;
return V_5 ;
}
F_53 ( V_33 , F_54 ( V_2 ) ) ;
F_55 ( V_33 ) ;
F_56 ( V_1 , V_33 ) ;
F_57 ( V_1 , V_33 ) ;
F_52 ( V_1 ) ;
F_58 ( ( & F_29 ( V_2 ) -> V_40 ) ) ;
F_59 ( V_2 , V_41 ) ;
F_60 ( ( & F_29 ( V_2 ) -> V_40 ) ) ;
V_1 = F_47 ( V_2 , V_58 , 1 ) ;
if ( F_6 ( V_1 ) ) {
F_61 ( NULL , V_33 ) ;
V_5 = F_7 ( V_1 ) ;
goto V_63;
}
V_35 = F_29 ( V_2 ) ;
V_23 = V_35 -> V_23 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_25 = V_2 -> V_26 -> V_27 >> 2 ;
for ( V_24 = 0 ; V_24 < V_64 ; V_24 ++ ) {
if ( V_23 [ V_24 ] ) {
V_5 = F_15 ( V_1 , V_33 ,
F_18 ( V_23 [ V_24 ] ) , & V_4 ) ;
if ( V_5 )
goto V_16;
} else
V_4 . V_20 ++ ;
}
if ( V_23 [ V_37 ] ) {
V_5 = F_16 ( V_1 , V_33 ,
F_18 ( V_23 [ V_37 ] ) , & V_4 ) ;
if ( V_5 )
goto V_16;
} else
V_4 . V_20 += V_25 ;
if ( V_23 [ V_38 ] ) {
V_5 = F_20 ( V_1 , V_33 ,
F_18 ( V_23 [ V_38 ] ) , & V_4 ) ;
if ( V_5 )
goto V_16;
} else
V_4 . V_20 += V_25 * V_25 ;
if ( V_23 [ V_39 ] ) {
V_5 = F_21 ( V_1 , V_33 ,
F_18 ( V_23 [ V_39 ] ) , & V_4 ) ;
if ( V_5 )
goto V_16;
}
V_5 = F_1 ( V_1 , V_33 , & V_4 ) ;
V_16:
if ( V_5 )
F_42 ( V_1 , V_33 ) ;
else {
V_5 = F_28 ( V_1 , V_2 , V_33 ) ;
if ( V_5 )
F_42 ( V_1 , V_33 ) ;
}
if ( F_11 ( V_1 , 1 ) != 0 )
F_10 ( V_1 , 1 ) ;
F_53 ( V_33 , 0 ) ;
V_33 -> V_45 = 0 ;
F_56 ( V_1 , V_33 ) ;
F_52 ( V_1 ) ;
V_63:
F_62 ( V_33 ) ;
F_63 ( V_33 ) ;
return V_5 ;
}
int F_64 ( struct V_2 * V_2 )
{
struct V_49 * V_50 ;
struct V_65 * V_66 = F_65 ( V_2 -> V_26 ) -> V_67 ;
struct V_34 * V_35 = F_29 ( V_2 ) ;
struct V_7 * V_68 ;
unsigned int V_24 , V_69 ;
T_2 V_70 ;
T_1 * V_1 ;
int V_71 ;
if ( ! F_44 ( V_2 -> V_26 ,
V_55 ) ||
( ! F_45 ( V_2 , V_43 ) ) )
return - V_56 ;
if ( F_66 ( V_2 -> V_26 ,
V_72 ) )
return - V_73 ;
V_1 = F_47 ( V_2 , V_58 , 1 ) ;
if ( F_6 ( V_1 ) )
return F_7 ( V_1 ) ;
F_30 ( & F_29 ( V_2 ) -> V_40 ) ;
V_71 = F_67 ( V_2 ) ;
if ( V_71 )
goto V_74;
V_50 = F_68 ( V_2 ) ;
V_68 = F_69 ( V_50 ) ;
if ( F_70 ( V_66 ) > V_75 ||
V_50 -> V_51 != 0 || F_41 ( V_50 -> V_52 ) > 1 ) {
V_71 = - V_73 ;
goto V_74;
}
if ( V_50 -> V_52 == 0 )
V_70 = V_69 = 0 ;
else {
V_69 = F_41 ( V_68 -> V_14 ) ;
V_70 = F_71 ( V_68 ) ;
if ( V_69 > V_64 ) {
V_71 = - V_73 ;
goto V_74;
}
}
F_72 ( V_2 , V_43 ) ;
memset ( V_35 -> V_23 , 0 , sizeof( V_35 -> V_23 ) ) ;
for ( V_24 = 0 ; V_24 < V_69 ; V_24 ++ )
V_35 -> V_23 [ V_24 ] = F_2 ( V_70 ++ ) ;
F_37 ( V_1 , V_2 ) ;
V_74:
F_52 ( V_1 ) ;
F_32 ( & F_29 ( V_2 ) -> V_40 ) ;
return V_71 ;
}
