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
F_5 ( & F_6 ( V_2 ) -> V_16 ) ;
V_10 = F_7 ( V_2 , V_4 -> V_13 , NULL , 0 ) ;
if ( F_8 ( V_10 ) ) {
V_5 = F_9 ( V_10 ) ;
V_10 = NULL ;
goto V_17;
}
V_6 = F_10 ( V_2 ,
V_4 -> V_15 - V_4 -> V_13 + 1 , V_10 ) ;
if ( V_6 && F_11 ( V_1 ,
V_18 ) ) {
F_12 ( ( & F_6 ( V_2 ) -> V_16 ) ) ;
V_5 = F_13 ( V_1 , V_6 ) ;
F_5 ( ( & F_6 ( V_2 ) -> V_16 ) ) ;
if ( V_5 )
goto V_17;
} else if ( V_6 ) {
V_5 = F_14 ( V_1 , V_6 ) ;
if ( V_5 ) {
F_12 ( ( & F_6 ( V_2 ) -> V_16 ) ) ;
V_5 = F_13 ( V_1 , V_6 ) ;
F_5 ( ( & F_6 ( V_2 ) -> V_16 ) ) ;
if ( V_5 )
goto V_17;
}
}
V_5 = F_15 ( V_1 , V_2 , & V_10 , & V_8 , 0 ) ;
V_17:
F_12 ( ( & F_6 ( V_2 ) -> V_16 ) ) ;
F_16 ( V_10 ) ;
F_17 ( V_10 ) ;
V_4 -> V_11 = 0 ;
return V_5 ;
}
static int F_18 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_19 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_11 &&
( V_4 -> V_20 + 1 == V_19 ) &&
( V_4 -> V_15 + 1 == V_4 -> V_21 ) ) {
V_4 -> V_20 = V_19 ;
V_4 -> V_15 = V_4 -> V_21 ;
V_4 -> V_21 ++ ;
return 0 ;
}
V_5 = F_1 ( V_1 , V_2 , V_4 ) ;
V_4 -> V_11 = V_4 -> V_20 = V_19 ;
V_4 -> V_13 = V_4 -> V_15 = V_4 -> V_21 ;
V_4 -> V_21 ++ ;
return V_5 ;
}
static int F_19 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_19 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 ;
T_3 * V_24 ;
int V_25 , V_5 = 0 ;
unsigned long V_26 = V_2 -> V_27 -> V_28 >> 2 ;
V_23 = F_20 ( V_2 -> V_27 , V_19 ) ;
if ( ! V_23 )
return - V_29 ;
V_24 = ( T_3 * ) V_23 -> V_30 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_18 ( V_1 , V_2 ,
F_21 ( V_24 [ V_25 ] ) , V_4 ) ;
if ( V_5 )
break;
} else {
V_4 -> V_21 ++ ;
}
}
F_22 ( V_23 ) ;
return V_5 ;
}
static int F_23 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_19 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 ;
T_3 * V_24 ;
int V_25 , V_5 = 0 ;
unsigned long V_26 = V_2 -> V_27 -> V_28 >> 2 ;
V_23 = F_20 ( V_2 -> V_27 , V_19 ) ;
if ( ! V_23 )
return - V_29 ;
V_24 = ( T_3 * ) V_23 -> V_30 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_19 ( V_1 , V_2 ,
F_21 ( V_24 [ V_25 ] ) , V_4 ) ;
if ( V_5 )
break;
} else {
V_4 -> V_21 += V_26 ;
}
}
F_22 ( V_23 ) ;
return V_5 ;
}
static int F_24 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_19 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 ;
T_3 * V_24 ;
int V_25 , V_5 = 0 ;
unsigned long V_26 = V_2 -> V_27 -> V_28 >> 2 ;
V_23 = F_20 ( V_2 -> V_27 , V_19 ) ;
if ( ! V_23 )
return - V_29 ;
V_24 = ( T_3 * ) V_23 -> V_30 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_23 ( V_1 , V_2 ,
F_21 ( V_24 [ V_25 ] ) , V_4 ) ;
if ( V_5 )
break;
} else {
V_4 -> V_21 += V_26 * V_26 ;
}
}
F_22 ( V_23 ) ;
return V_5 ;
}
static int F_25 ( T_1 * V_1 , struct V_2 * V_2 )
{
int V_5 = 0 , V_6 ;
if ( F_11 ( V_1 , V_18 + 1 ) )
return 0 ;
V_6 = 3 + F_26 ( V_2 -> V_27 ) ;
if ( F_14 ( V_1 , V_6 ) != 0 )
V_5 = F_13 ( V_1 , V_6 ) ;
return V_5 ;
}
static int F_27 ( T_1 * V_1 ,
struct V_2 * V_2 , T_3 V_24 )
{
int V_25 ;
T_3 * V_31 ;
struct V_22 * V_23 ;
unsigned long V_26 = V_2 -> V_27 -> V_28 >> 2 ;
V_23 = F_20 ( V_2 -> V_27 , F_21 ( V_24 ) ) ;
if ( ! V_23 )
return - V_29 ;
V_31 = ( T_3 * ) V_23 -> V_30 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_31 [ V_25 ] ) {
F_25 ( V_1 , V_2 ) ;
F_28 ( V_1 , V_2 , NULL ,
F_21 ( V_31 [ V_25 ] ) , 1 ,
V_32 |
V_33 ) ;
}
}
F_22 ( V_23 ) ;
F_25 ( V_1 , V_2 ) ;
F_28 ( V_1 , V_2 , NULL , F_21 ( V_24 ) , 1 ,
V_32 |
V_33 ) ;
return 0 ;
}
static int F_29 ( T_1 * V_1 ,
struct V_2 * V_2 , T_3 V_24 )
{
int V_25 , V_5 = 0 ;
T_3 * V_31 ;
struct V_22 * V_23 ;
unsigned long V_26 = V_2 -> V_27 -> V_28 >> 2 ;
V_23 = F_20 ( V_2 -> V_27 , F_21 ( V_24 ) ) ;
if ( ! V_23 )
return - V_29 ;
V_31 = ( T_3 * ) V_23 -> V_30 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_31 [ V_25 ] ) {
V_5 = F_27 ( V_1 ,
V_2 , V_31 [ V_25 ] ) ;
if ( V_5 ) {
F_22 ( V_23 ) ;
return V_5 ;
}
}
}
F_22 ( V_23 ) ;
F_25 ( V_1 , V_2 ) ;
F_28 ( V_1 , V_2 , NULL , F_21 ( V_24 ) , 1 ,
V_32 |
V_33 ) ;
return 0 ;
}
static int F_30 ( T_1 * V_1 , struct V_2 * V_2 , T_3 * V_24 )
{
int V_5 ;
if ( V_24 [ 0 ] ) {
F_25 ( V_1 , V_2 ) ;
F_28 ( V_1 , V_2 , NULL ,
F_21 ( V_24 [ 0 ] ) , 1 ,
V_32 |
V_33 ) ;
}
if ( V_24 [ 1 ] ) {
V_5 = F_27 ( V_1 , V_2 , V_24 [ 1 ] ) ;
if ( V_5 )
return V_5 ;
}
if ( V_24 [ 2 ] ) {
V_5 = F_29 ( V_1 , V_2 , V_24 [ 2 ] ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_31 ( T_1 * V_1 , struct V_2 * V_2 ,
struct V_2 * V_34 )
{
int V_5 ;
T_3 V_24 [ 3 ] ;
struct V_35 * V_36 = F_6 ( V_2 ) ;
struct V_35 * V_37 = F_6 ( V_34 ) ;
V_5 = F_14 ( V_1 , 1 ) ;
if ( V_5 ) {
V_5 = F_13 ( V_1 , 1 ) ;
if ( V_5 )
goto V_17;
}
V_24 [ 0 ] = V_36 -> V_24 [ V_38 ] ;
V_24 [ 1 ] = V_36 -> V_24 [ V_39 ] ;
V_24 [ 2 ] = V_36 -> V_24 [ V_40 ] ;
F_5 ( & F_6 ( V_2 ) -> V_16 ) ;
if ( ! F_32 ( V_2 , V_41 ) ) {
V_5 = - V_42 ;
F_12 ( & F_6 ( V_2 ) -> V_16 ) ;
goto V_17;
} else
F_33 ( V_2 , V_41 ) ;
F_34 ( V_2 , V_43 ) ;
memcpy ( V_36 -> V_24 , V_37 -> V_24 , sizeof( V_36 -> V_24 ) ) ;
F_35 ( & V_2 -> V_44 ) ;
V_2 -> V_45 += V_34 -> V_45 ;
F_36 ( & V_2 -> V_44 ) ;
F_12 ( & F_6 ( V_2 ) -> V_16 ) ;
V_5 = F_30 ( V_1 , V_2 , V_24 ) ;
F_37 ( V_1 , V_2 ) ;
V_17:
return V_5 ;
}
static int F_38 ( T_1 * V_1 , struct V_2 * V_2 ,
struct V_46 * V_47 )
{
int V_25 , V_5 = 0 ;
T_2 V_48 ;
struct V_22 * V_23 ;
struct V_49 * V_50 ;
V_48 = F_39 ( V_47 ) ;
V_23 = F_20 ( V_2 -> V_27 , V_48 ) ;
if ( ! V_23 )
return - V_29 ;
V_50 = (struct V_49 * ) V_23 -> V_30 ;
if ( V_50 -> V_51 != 0 ) {
V_47 = F_40 ( V_50 ) ;
for ( V_25 = 0 ; V_25 < F_41 ( V_50 -> V_52 ) ; V_25 ++ , V_47 ++ ) {
V_5 = F_38 ( V_1 , V_2 , V_47 ) ;
if ( V_5 )
break;
}
}
F_22 ( V_23 ) ;
F_25 ( V_1 , V_2 ) ;
F_28 ( V_1 , V_2 , NULL , V_48 , 1 ,
V_32 | V_33 ) ;
return V_5 ;
}
static int F_42 ( T_1 * V_1 , struct V_2 * V_2 )
{
int V_25 , V_5 = 0 ;
struct V_35 * V_36 = F_6 ( V_2 ) ;
struct V_49 * V_50 = (struct V_49 * ) V_36 -> V_24 ;
struct V_46 * V_47 ;
if ( V_50 -> V_51 == 0 )
return 0 ;
V_47 = F_40 ( V_50 ) ;
for ( V_25 = 0 ; V_25 < F_41 ( V_50 -> V_52 ) ; V_25 ++ , V_47 ++ ) {
V_5 = F_38 ( V_1 , V_2 , V_47 ) ;
if ( V_5 )
return V_5 ;
}
return V_5 ;
}
int F_43 ( struct V_2 * V_2 )
{
T_1 * V_1 ;
int V_5 = 0 , V_25 ;
T_3 * V_24 ;
struct V_35 * V_36 ;
struct V_2 * V_34 = NULL ;
struct V_3 V_4 ;
unsigned long V_26 ;
T_4 V_53 ;
T_5 V_54 [ 2 ] ;
if ( ! F_44 ( V_2 -> V_27 ) ||
( F_45 ( V_2 , V_43 ) ) )
return - V_55 ;
if ( F_46 ( V_2 -> V_56 ) && V_2 -> V_45 == 0 )
return V_5 ;
V_1 = F_47 ( V_2 , V_57 ,
4 + F_26 ( V_2 -> V_27 ) ) ;
if ( F_8 ( V_1 ) ) {
V_5 = F_9 ( V_1 ) ;
return V_5 ;
}
V_53 = ( ( ( V_2 -> V_58 - 1 ) / F_48 ( V_2 -> V_27 ) ) *
F_48 ( V_2 -> V_27 ) ) + 1 ;
V_54 [ 0 ] = F_49 ( V_2 ) ;
V_54 [ 1 ] = F_50 ( V_2 ) ;
V_34 = F_51 ( V_1 , F_52 ( V_2 -> V_27 -> V_59 ) ,
V_60 , NULL , V_53 , V_54 , 0 ) ;
if ( F_8 ( V_34 ) ) {
V_5 = F_9 ( V_34 ) ;
F_53 ( V_1 ) ;
return V_5 ;
}
F_54 ( V_34 , F_55 ( V_2 ) ) ;
F_56 ( V_34 ) ;
F_57 ( V_1 , V_34 ) ;
F_58 ( V_1 , V_34 ) ;
F_53 ( V_1 ) ;
F_59 ( & F_6 ( V_2 ) -> V_16 ) ;
F_60 ( V_2 , V_41 ) ;
F_61 ( ( & F_6 ( V_2 ) -> V_16 ) ) ;
V_1 = F_47 ( V_2 , V_57 , 1 ) ;
if ( F_8 ( V_1 ) ) {
F_62 ( NULL , V_34 ) ;
V_5 = F_9 ( V_1 ) ;
goto V_61;
}
V_36 = F_6 ( V_2 ) ;
V_24 = V_36 -> V_24 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_26 = V_2 -> V_27 -> V_28 >> 2 ;
for ( V_25 = 0 ; V_25 < V_62 ; V_25 ++ ) {
if ( V_24 [ V_25 ] ) {
V_5 = F_18 ( V_1 , V_34 ,
F_21 ( V_24 [ V_25 ] ) , & V_4 ) ;
if ( V_5 )
goto V_17;
} else
V_4 . V_21 ++ ;
}
if ( V_24 [ V_38 ] ) {
V_5 = F_19 ( V_1 , V_34 ,
F_21 ( V_24 [ V_38 ] ) , & V_4 ) ;
if ( V_5 )
goto V_17;
} else
V_4 . V_21 += V_26 ;
if ( V_24 [ V_39 ] ) {
V_5 = F_23 ( V_1 , V_34 ,
F_21 ( V_24 [ V_39 ] ) , & V_4 ) ;
if ( V_5 )
goto V_17;
} else
V_4 . V_21 += V_26 * V_26 ;
if ( V_24 [ V_40 ] ) {
V_5 = F_24 ( V_1 , V_34 ,
F_21 ( V_24 [ V_40 ] ) , & V_4 ) ;
if ( V_5 )
goto V_17;
}
V_5 = F_1 ( V_1 , V_34 , & V_4 ) ;
V_17:
if ( V_5 )
F_42 ( V_1 , V_34 ) ;
else {
V_5 = F_31 ( V_1 , V_2 , V_34 ) ;
if ( V_5 )
F_42 ( V_1 , V_34 ) ;
}
if ( F_14 ( V_1 , 1 ) != 0 )
F_13 ( V_1 , 1 ) ;
F_54 ( V_34 , 0 ) ;
V_34 -> V_45 = 0 ;
F_57 ( V_1 , V_34 ) ;
F_53 ( V_1 ) ;
V_61:
F_63 ( V_34 ) ;
F_64 ( V_34 ) ;
return V_5 ;
}
int F_65 ( struct V_2 * V_2 )
{
struct V_49 * V_50 ;
struct V_63 * V_64 = F_66 ( V_2 -> V_27 ) -> V_65 ;
struct V_35 * V_36 = F_6 ( V_2 ) ;
struct V_7 * V_66 ;
unsigned int V_25 , V_67 ;
T_6 V_68 , V_69 ;
T_2 V_70 ;
T_1 * V_1 ;
int V_71 ;
if ( ! F_44 ( V_2 -> V_27 ) ||
( ! F_45 ( V_2 , V_43 ) ) )
return - V_55 ;
if ( F_67 ( V_2 -> V_27 ) )
return - V_72 ;
if ( F_68 ( V_2 -> V_27 , V_73 ) )
F_69 ( V_2 ) ;
V_1 = F_47 ( V_2 , V_57 , 1 ) ;
if ( F_8 ( V_1 ) )
return F_9 ( V_1 ) ;
F_5 ( & F_6 ( V_2 ) -> V_16 ) ;
V_71 = F_70 ( V_2 ) ;
if ( V_71 )
goto V_74;
V_50 = F_71 ( V_2 ) ;
V_66 = F_72 ( V_50 ) ;
if ( F_73 ( V_64 ) > V_75 ||
V_50 -> V_51 != 0 || F_41 ( V_50 -> V_52 ) > 1 ) {
V_71 = - V_72 ;
goto V_74;
}
if ( V_50 -> V_52 == 0 )
V_70 = V_67 = V_68 = V_69 = 0 ;
else {
V_67 = F_41 ( V_66 -> V_14 ) ;
V_70 = F_74 ( V_66 ) ;
V_68 = F_21 ( V_66 -> V_12 ) ;
V_69 = V_68 + V_67 - 1 ;
if ( V_69 >= V_62 ) {
V_71 = - V_72 ;
goto V_74;
}
}
F_75 ( V_2 , V_43 ) ;
memset ( V_36 -> V_24 , 0 , sizeof( V_36 -> V_24 ) ) ;
for ( V_25 = V_68 ; V_25 <= V_69 ; V_25 ++ )
V_36 -> V_24 [ V_25 ] = F_2 ( V_70 ++ ) ;
F_37 ( V_1 , V_2 ) ;
V_74:
F_53 ( V_1 ) ;
F_12 ( & F_6 ( V_2 ) -> V_16 ) ;
return V_71 ;
}
