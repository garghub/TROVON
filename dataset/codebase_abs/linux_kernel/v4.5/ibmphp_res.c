static struct V_1 * T_1 F_1 ( struct V_2 * V_3 , T_2 V_4 , int V_5 )
{
struct V_1 * V_6 ;
if ( ! ( V_3 ) && ! ( V_5 ) ) {
F_2 ( L_1 ) ;
return NULL ;
}
V_6 = F_3 ( sizeof( struct V_1 ) , V_7 ) ;
if ( ! V_6 ) {
F_2 ( L_2 ) ;
return NULL ;
}
if ( V_5 )
V_6 -> V_4 = V_4 ;
else
V_6 -> V_4 = V_3 -> V_8 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
return V_6 ;
}
static struct V_11 * T_1 F_5 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
if ( ! V_3 ) {
F_2 ( L_3 ) ;
return NULL ;
}
V_12 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_12 ) {
F_2 ( L_2 ) ;
return NULL ;
}
V_12 -> V_4 = V_3 -> V_8 ;
V_12 -> V_13 = V_3 -> V_14 ;
V_12 -> V_15 = V_3 -> V_16 ;
V_12 -> V_17 = V_3 -> V_18 ;
V_12 -> V_19 = V_3 -> V_18 - V_3 -> V_16 + 1 ;
return V_12 ;
}
static int T_1 F_6 ( struct V_1 * * V_20 , struct V_21 * * V_22 , struct V_2 * V_3 , int V_5 , T_2 V_23 )
{
struct V_1 * V_6 ;
struct V_21 * V_24 ;
T_2 V_25 = 0 ;
if ( V_23 ) {
V_6 = F_3 ( sizeof( struct V_1 ) , V_7 ) ;
if ( ! V_6 ) {
F_2 ( L_4 ) ;
return - V_26 ;
}
V_6 -> V_4 = V_3 -> V_8 ;
} else {
V_6 = * V_20 ;
switch ( V_5 ) {
case V_27 :
V_25 = V_6 -> V_28 ;
break;
case V_29 :
V_25 = V_6 -> V_30 ;
break;
case V_31 :
V_25 = V_6 -> V_32 ;
break;
}
}
V_24 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_24 ) {
if ( V_23 )
F_7 ( V_6 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_24 -> V_15 = V_3 -> V_16 ;
V_24 -> V_17 = V_3 -> V_18 ;
if ( V_23 || ( ! V_25 ) )
V_24 -> V_33 = 1 ;
else {
F_8 ( V_5 , V_24 , V_6 ) ;
F_9 ( L_5 , V_5 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
switch ( V_5 ) {
case V_27 :
V_6 -> V_34 = V_24 ;
if ( V_23 )
V_6 -> V_28 = 1 ;
else {
F_9 ( L_6 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
++ V_6 -> V_28 ;
F_10 ( V_6 ) ;
}
break;
case V_31 :
V_6 -> V_35 = V_24 ;
if ( V_23 )
V_6 -> V_32 = 1 ;
else {
F_9 ( L_7 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
++ V_6 -> V_32 ;
F_10 ( V_6 ) ;
}
break;
case V_29 :
V_6 -> V_36 = V_24 ;
if ( V_23 )
V_6 -> V_30 = 1 ;
else {
F_9 ( L_8 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
++ V_6 -> V_30 ;
F_10 ( V_6 ) ;
}
break;
}
* V_20 = V_6 ;
* V_22 = V_24 ;
return 0 ;
}
int T_1 F_11 ( void )
{
struct V_2 * V_3 ;
struct V_21 * V_24 = NULL ;
struct V_1 * V_6 = NULL ;
struct V_1 * V_37 ;
struct V_1 * V_38 ;
struct V_11 * V_39 = NULL ;
struct V_11 * V_40 = NULL ;
struct V_11 * V_41 = NULL ;
int V_42 ;
F_12 (curr, &ibmphp_ebda_pci_rsrc_head,
ebda_pci_rsrc_list) {
if ( ! ( V_3 -> V_43 & V_44 ) ) {
F_9 ( L_9 ) ;
}
if ( V_3 -> V_43 & V_45 ) {
if ( ( V_3 -> V_43 & V_46 ) == V_47 ) {
if ( F_13 ( & V_10 ) ) {
V_42 = F_6 ( & V_6 , & V_24 , V_3 , V_27 , 1 ) ;
if ( V_42 )
return V_42 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_10 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
} else {
V_37 = F_14 ( V_3 -> V_8 , & V_38 , 1 ) ;
if ( V_37 ) {
V_42 = F_6 ( & V_37 , & V_24 , V_3 , V_27 , 0 ) ;
if ( V_42 )
return V_42 ;
} else {
V_42 = F_6 ( & V_6 , & V_24 , V_3 , V_27 , 1 ) ;
if ( V_42 )
return V_42 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_11 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
}
} else if ( ( V_3 -> V_43 & V_46 ) == V_48 ) {
if ( F_13 ( & V_10 ) ) {
V_42 = F_6 ( & V_6 , & V_24 , V_3 , V_29 , 1 ) ;
if ( V_42 )
return V_42 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_12 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
} else {
V_37 = F_14 ( V_3 -> V_8 , & V_38 , 1 ) ;
if ( V_37 ) {
V_42 = F_6 ( & V_37 , & V_24 , V_3 , V_29 , 0 ) ;
if ( V_42 )
return V_42 ;
} else {
V_42 = F_6 ( & V_6 , & V_24 , V_3 , V_29 , 1 ) ;
if ( V_42 )
return V_42 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_13 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
}
} else if ( ( V_3 -> V_43 & V_46 ) == V_49 ) {
if ( F_13 ( & V_10 ) ) {
V_42 = F_6 ( & V_6 , & V_24 , V_3 , V_31 , 1 ) ;
if ( V_42 )
return V_42 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_14 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
} else {
V_37 = F_14 ( V_3 -> V_8 , & V_38 , 1 ) ;
if ( V_37 ) {
V_42 = F_6 ( & V_37 , & V_24 , V_3 , V_31 , 0 ) ;
if ( V_42 )
return V_42 ;
} else {
V_42 = F_6 ( & V_6 , & V_24 , V_3 , V_31 , 1 ) ;
if ( V_42 )
return V_42 ;
F_4 ( & V_6 -> V_9 , & V_10 ) ;
F_9 ( L_15 , V_6 -> V_4 , V_24 -> V_15 , V_24 -> V_17 ) ;
}
}
} else {
;
}
} else {
if ( ( V_3 -> V_43 & V_46 ) == V_47 ) {
V_40 = F_5 ( V_3 ) ;
if ( ! V_40 )
return - V_26 ;
V_40 -> type = V_27 ;
if ( F_15 ( V_40 ) < 0 ) {
V_6 = F_1 ( V_3 , 0 , 0 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_50 = V_40 ;
++ V_6 -> V_51 ;
V_40 -> V_33 = - 1 ;
}
F_9 ( L_16 , V_40 -> V_13 , V_40 -> V_4 , V_40 -> V_15 , V_40 -> V_17 ) ;
} else if ( ( V_3 -> V_43 & V_46 ) == V_48 ) {
V_41 = F_5 ( V_3 ) ;
if ( ! V_41 )
return - V_26 ;
V_41 -> type = V_29 ;
V_41 -> V_52 = 0 ;
if ( F_15 ( V_41 ) < 0 ) {
V_6 = F_1 ( V_3 , 0 , 0 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_53 = V_41 ;
++ V_6 -> V_54 ;
V_41 -> V_33 = - 1 ;
}
F_9 ( L_17 , V_41 -> V_13 , V_41 -> V_4 , V_41 -> V_15 , V_41 -> V_17 ) ;
} else if ( ( V_3 -> V_43 & V_46 ) == V_49 ) {
V_39 = F_5 ( V_3 ) ;
if ( ! V_39 )
return - V_26 ;
V_39 -> type = V_31 ;
if ( F_15 ( V_39 ) < 0 ) {
V_6 = F_1 ( V_3 , 0 , 0 ) ;
if ( ! V_6 )
return - V_26 ;
V_6 -> V_55 = V_39 ;
++ V_6 -> V_56 ;
V_39 -> V_33 = - 1 ;
}
F_9 ( L_18 , V_39 -> V_13 , V_39 -> V_4 , V_39 -> V_15 , V_39 -> V_17 ) ;
}
}
}
F_12 (bus_cur, &gbuses, bus_list) {
V_42 = F_16 ( & V_37 ) ;
if ( V_42 )
return V_42 ;
}
return F_17 () ;
}
static int F_8 ( int type , struct V_21 * V_57 , struct V_1 * V_37 )
{
struct V_21 * V_58 = NULL ;
struct V_21 * V_59 ;
int V_60 = 0 , V_61 ;
int V_62 = 0 ;
switch ( type ) {
case V_27 :
V_58 = V_37 -> V_34 ;
V_62 = V_37 -> V_28 ;
break;
case V_29 :
V_58 = V_37 -> V_36 ;
V_62 = V_37 -> V_30 ;
break;
case V_31 :
V_58 = V_37 -> V_35 ;
V_62 = V_37 -> V_32 ;
break;
}
V_59 = NULL ;
while ( V_58 ) {
if ( V_57 -> V_15 < V_58 -> V_15 )
break;
V_59 = V_58 ;
V_58 = V_58 -> V_63 ;
V_60 = V_60 + 1 ;
}
if ( ! V_60 ) {
switch ( type ) {
case V_27 :
V_37 -> V_34 = V_57 ;
break;
case V_29 :
V_37 -> V_36 = V_57 ;
break;
case V_31 :
V_37 -> V_35 = V_57 ;
break;
}
V_57 -> V_63 = V_58 ;
V_57 -> V_33 = 1 ;
V_61 = 0 ;
} else if ( ! V_58 ) {
V_57 -> V_63 = NULL ;
V_59 -> V_63 = V_57 ;
V_57 -> V_33 = V_59 -> V_33 + 1 ;
return 0 ;
} else {
V_59 -> V_63 = V_57 ;
V_57 -> V_63 = V_58 ;
V_57 -> V_33 = V_58 -> V_33 ;
V_61 = V_59 -> V_33 ;
}
for ( V_60 = V_61 ; V_60 < V_62 ; ++ V_60 ) {
++ V_58 -> V_33 ;
V_58 = V_58 -> V_63 ;
}
F_18 ( V_37 , type , V_61 + 1 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_37 , int type , int V_33 )
{
struct V_11 * V_64 = NULL ;
T_2 V_65 = 0 ;
switch ( type ) {
case V_27 :
if ( V_37 -> V_50 )
V_64 = V_37 -> V_50 ;
break;
case V_29 :
if ( V_37 -> V_53 )
V_64 = V_37 -> V_53 ;
break;
case V_31 :
if ( V_37 -> V_55 )
V_64 = V_37 -> V_55 ;
break;
}
if ( V_64 ) {
while ( V_64 ) {
if ( V_64 -> V_33 == V_33 )
break;
if ( V_64 -> V_63 )
V_64 = V_64 -> V_63 ;
else if ( V_64 -> V_66 )
V_64 = V_64 -> V_66 ;
else {
V_65 = 1 ;
break;
}
}
if ( ! V_65 ) {
while ( V_64 ) {
++ V_64 -> V_33 ;
V_64 = V_64 -> V_63 ;
}
}
}
}
static void F_19 ( struct V_11 * V_64 , struct V_1 * V_37 , struct V_21 * V_57 )
{
char * V_67 = L_19 ;
switch ( V_64 -> type ) {
case V_31 :
V_67 = L_20 ;
break;
case V_27 :
V_67 = L_21 ;
break;
case V_29 :
V_67 = L_22 ;
break;
}
while ( V_64 ) {
if ( V_64 -> V_33 == - 1 ) {
while ( V_57 ) {
if ( ( V_64 -> V_15 >= V_57 -> V_15 ) && ( V_64 -> V_17 <= V_57 -> V_17 ) ) {
V_64 -> V_33 = V_57 -> V_33 ;
F_9 ( L_23 , V_67 , V_64 -> V_33 ) ;
switch ( V_64 -> type ) {
case V_31 :
-- V_37 -> V_56 ;
break;
case V_27 :
-- V_37 -> V_51 ;
break;
case V_29 :
-- V_37 -> V_54 ;
break;
}
break;
}
V_57 = V_57 -> V_63 ;
}
}
if ( V_64 -> V_63 )
V_64 = V_64 -> V_63 ;
else
V_64 = V_64 -> V_66 ;
}
}
static void F_10 ( struct V_1 * V_37 )
{
struct V_21 * V_57 ;
struct V_11 * V_64 ;
F_9 ( L_24 , V_68 , V_37 -> V_4 ) ;
if ( V_37 -> V_56 ) {
V_64 = V_37 -> V_55 ;
V_57 = V_37 -> V_35 ;
F_19 ( V_64 , V_37 , V_57 ) ;
}
if ( V_37 -> V_51 ) {
V_64 = V_37 -> V_50 ;
V_57 = V_37 -> V_34 ;
F_19 ( V_64 , V_37 , V_57 ) ;
}
if ( V_37 -> V_54 ) {
V_64 = V_37 -> V_53 ;
V_57 = V_37 -> V_36 ;
F_19 ( V_64 , V_37 , V_57 ) ;
}
}
int F_15 ( struct V_11 * V_64 )
{
struct V_11 * V_69 ;
struct V_11 * V_70 ;
struct V_1 * V_37 ;
struct V_21 * V_58 = NULL ;
struct V_11 * V_71 = NULL ;
F_9 ( L_25 , V_68 ) ;
if ( ! V_64 ) {
F_2 ( L_26 ) ;
return - V_72 ;
}
V_37 = F_14 ( V_64 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_9 ( L_27 ) ;
return - V_72 ;
}
switch ( V_64 -> type ) {
case V_31 :
V_58 = V_37 -> V_35 ;
V_71 = V_37 -> V_55 ;
break;
case V_27 :
V_58 = V_37 -> V_34 ;
V_71 = V_37 -> V_50 ;
break;
case V_29 :
V_58 = V_37 -> V_36 ;
V_71 = V_37 -> V_53 ;
break;
default:
F_2 ( L_28 ) ;
return - V_73 ;
}
while ( V_58 ) {
if ( ( V_64 -> V_15 >= V_58 -> V_15 ) && ( V_64 -> V_17 <= V_58 -> V_17 ) ) {
V_64 -> V_33 = V_58 -> V_33 ;
break;
}
V_58 = V_58 -> V_63 ;
}
if ( ! V_58 ) {
switch ( V_64 -> type ) {
case V_31 :
++ V_37 -> V_56 ;
break;
case V_27 :
++ V_37 -> V_51 ;
break;
case V_29 :
++ V_37 -> V_54 ;
break;
}
V_64 -> V_33 = - 1 ;
}
F_9 ( L_29 , V_64 -> V_33 ) ;
if ( ! V_71 ) {
switch ( V_64 -> type ) {
case V_31 :
V_37 -> V_55 = V_64 ;
break;
case V_27 :
V_37 -> V_50 = V_64 ;
break;
case V_29 :
V_37 -> V_53 = V_64 ;
break;
}
V_64 -> V_63 = NULL ;
V_64 -> V_66 = NULL ;
} else {
V_69 = V_71 ;
V_70 = NULL ;
F_9 ( L_30 , V_69 -> V_33 ) ;
while ( V_69 ) {
if ( V_69 -> V_33 >= V_64 -> V_33 )
break;
V_70 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
}
if ( ! V_69 ) {
F_9 ( L_31 , V_64 -> V_15 , V_64 -> V_17 ) ;
V_70 -> V_66 = V_64 ;
V_64 -> V_63 = NULL ;
V_64 -> V_66 = NULL ;
} else if ( V_69 -> V_33 == V_64 -> V_33 ) {
while ( V_69 ) {
if ( V_64 -> V_15 < V_69 -> V_15 )
break;
V_70 = V_69 ;
V_69 = V_69 -> V_63 ;
}
if ( ! V_69 ) {
V_70 -> V_63 = V_64 ;
V_64 -> V_63 = NULL ;
V_64 -> V_66 = V_70 -> V_66 ;
V_70 -> V_66 = NULL ;
} else if ( V_64 -> V_15 < V_69 -> V_15 ) {
if ( ! V_70 ) {
switch ( V_64 -> type ) {
case V_31 :
V_37 -> V_55 = V_64 ;
break;
case V_27 :
V_37 -> V_50 = V_64 ;
break;
case V_29 :
V_37 -> V_53 = V_64 ;
break;
}
} else if ( V_70 -> V_33 == V_69 -> V_33 )
V_70 -> V_63 = V_64 ;
else
V_70 -> V_66 = V_64 ;
V_64 -> V_63 = V_69 ;
V_64 -> V_66 = NULL ;
}
} else {
if ( ! V_70 ) {
V_64 -> V_63 = NULL ;
switch ( V_64 -> type ) {
case V_31 :
V_64 -> V_66 = V_37 -> V_55 ;
V_37 -> V_55 = V_64 ;
break;
case V_27 :
V_64 -> V_66 = V_37 -> V_50 ;
V_37 -> V_50 = V_64 ;
break;
case V_29 :
V_64 -> V_66 = V_37 -> V_53 ;
V_37 -> V_53 = V_64 ;
break;
}
} else if ( V_69 -> V_33 > V_64 -> V_33 ) {
V_70 -> V_66 = V_64 ;
V_64 -> V_63 = NULL ;
V_64 -> V_66 = V_69 ;
}
}
}
F_9 ( L_32 , V_68 ) ;
return 0 ;
}
int F_20 ( struct V_11 * V_64 )
{
struct V_1 * V_37 ;
struct V_11 * V_69 = NULL ;
struct V_11 * V_70 ;
struct V_11 * V_74 ;
char * type = L_19 ;
if ( ! V_64 ) {
F_2 ( L_33 ) ;
return - V_72 ;
}
V_37 = F_14 ( V_64 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_2 ( L_34 ) ;
return - V_72 ;
}
switch ( V_64 -> type ) {
case V_31 :
V_69 = V_37 -> V_55 ;
type = L_20 ;
break;
case V_27 :
V_69 = V_37 -> V_50 ;
type = L_21 ;
break;
case V_29 :
V_69 = V_37 -> V_53 ;
type = L_22 ;
break;
default:
F_2 ( L_35 ) ;
return - V_73 ;
}
V_70 = NULL ;
while ( V_69 ) {
if ( ( V_69 -> V_15 == V_64 -> V_15 ) && ( V_69 -> V_17 == V_64 -> V_17 ) )
break;
V_70 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
}
if ( ! V_69 ) {
if ( V_64 -> type == V_29 ) {
V_69 = V_37 -> V_75 ;
V_70 = NULL ;
while ( V_69 ) {
if ( ( V_69 -> V_15 == V_64 -> V_15 ) && ( V_69 -> V_17 == V_64 -> V_17 ) ) {
V_74 = V_37 -> V_50 ;
while ( V_74 ) {
if ( ( V_74 -> V_15 == V_69 -> V_15 )
&& ( V_74 -> V_17 == V_69 -> V_17 ) )
break;
if ( V_74 -> V_63 )
V_74 = V_74 -> V_63 ;
else
V_74 = V_74 -> V_66 ;
}
if ( ! V_74 ) {
F_2 ( L_36 ) ;
return - V_73 ;
}
F_20 ( V_74 ) ;
if ( ! V_70 )
V_37 -> V_75 = V_69 -> V_63 ;
else
V_70 -> V_63 = V_69 -> V_63 ;
F_7 ( V_69 ) ;
return 0 ;
}
V_70 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
}
if ( ! V_69 ) {
F_2 ( L_37 ) ;
return - V_73 ;
}
} else {
F_2 ( L_38 , type ) ;
return - V_73 ;
}
}
if ( ! V_70 ) {
if ( V_69 -> V_63 ) {
switch ( V_64 -> type ) {
case V_31 :
V_37 -> V_55 = V_69 -> V_63 ;
break;
case V_27 :
V_37 -> V_50 = V_69 -> V_63 ;
break;
case V_29 :
V_37 -> V_53 = V_69 -> V_63 ;
break;
}
} else if ( V_69 -> V_66 ) {
switch ( V_64 -> type ) {
case V_31 :
V_37 -> V_55 = V_69 -> V_66 ;
break;
case V_27 :
V_37 -> V_50 = V_69 -> V_66 ;
break;
case V_29 :
V_37 -> V_53 = V_69 -> V_66 ;
break;
}
} else {
switch ( V_64 -> type ) {
case V_31 :
V_37 -> V_55 = NULL ;
break;
case V_27 :
V_37 -> V_50 = NULL ;
break;
case V_29 :
V_37 -> V_53 = NULL ;
break;
}
}
F_7 ( V_69 ) ;
return 0 ;
} else {
if ( V_69 -> V_63 ) {
if ( V_70 -> V_33 == V_69 -> V_33 )
V_70 -> V_63 = V_69 -> V_63 ;
else
V_70 -> V_66 = V_69 -> V_63 ;
} else if ( V_69 -> V_66 ) {
V_70 -> V_63 = NULL ;
V_70 -> V_66 = V_69 -> V_66 ;
} else {
V_70 -> V_63 = NULL ;
V_70 -> V_66 = NULL ;
}
F_7 ( V_69 ) ;
return 0 ;
}
return 0 ;
}
static struct V_21 * F_21 ( struct V_1 * V_37 , struct V_11 * V_64 )
{
struct V_21 * V_57 = NULL ;
switch ( V_64 -> type ) {
case V_31 :
V_57 = V_37 -> V_35 ;
break;
case V_27 :
V_57 = V_37 -> V_34 ;
break;
case V_29 :
V_57 = V_37 -> V_36 ;
break;
default:
F_2 ( L_39 ) ;
}
while ( V_57 ) {
if ( V_64 -> V_33 == V_57 -> V_33 )
break;
V_57 = V_57 -> V_63 ;
}
return V_57 ;
}
int F_22 ( struct V_11 * V_64 , T_2 V_76 )
{
struct V_1 * V_37 ;
struct V_21 * V_57 = NULL ;
struct V_11 * V_70 ;
struct V_11 * V_69 = NULL ;
T_3 V_77 = 0 , V_78 = 0 , V_79 = 0 ;
int V_80 = 0 ;
T_3 V_81 ;
T_3 V_82 ;
T_2 V_5 = 0 ;
if ( ! V_64 )
return - V_73 ;
if ( V_76 ) {
if ( V_64 -> type == V_31 )
V_82 = V_83 ;
else
V_82 = V_84 ;
} else
V_82 = V_64 -> V_19 ;
V_37 = F_14 ( V_64 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_9 ( L_27 ) ;
return - V_73 ;
}
F_9 ( L_25 , V_68 ) ;
F_9 ( L_40 , V_37 -> V_4 ) ;
V_64 -> V_19 -= 1 ;
switch ( V_64 -> type ) {
case V_31 :
V_69 = V_37 -> V_55 ;
V_80 = V_37 -> V_32 ;
break;
case V_27 :
V_69 = V_37 -> V_50 ;
V_80 = V_37 -> V_28 ;
break;
case V_29 :
V_69 = V_37 -> V_53 ;
V_80 = V_37 -> V_30 ;
break;
default:
F_2 ( L_41 ) ;
return - V_73 ;
}
V_70 = NULL ;
while ( V_69 ) {
V_57 = F_21 ( V_37 , V_69 ) ;
F_9 ( L_42 , V_68 , V_69 -> V_33 ) ;
if ( ! V_57 ) {
F_2 ( L_43 ) ;
return - V_73 ;
}
if ( ! V_70 ) {
V_79 = V_69 -> V_15 - 1 - V_57 -> V_15 ;
if ( ( V_69 -> V_15 != V_57 -> V_15 ) && ( V_79 >= V_64 -> V_19 ) ) {
F_9 ( L_44 , V_79 ) ;
if ( ( V_79 < V_77 ) || ( V_77 == 0 ) ) {
if ( ( V_57 -> V_15 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_57 -> V_15 ;
} else {
V_81 = V_57 -> V_15 ;
V_5 = 0 ;
while ( ( V_79 = V_69 -> V_15 - 1 - V_81 ) >= V_64 -> V_19 ) {
if ( ( V_81 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_81 ;
break;
}
V_81 += V_82 - V_81 % V_82 ;
if ( V_81 >= V_69 -> V_15 - 1 )
break;
}
}
if ( V_5 && V_77 == V_64 -> V_19 ) {
F_9 ( L_45 ) ;
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
}
}
}
if ( ! V_69 -> V_63 ) {
V_79 = V_57 -> V_17 - ( V_69 -> V_17 + 1 ) ;
if ( ( V_57 -> V_17 != V_69 -> V_17 ) && ( V_79 >= V_64 -> V_19 ) ) {
F_9 ( L_44 , V_79 ) ;
if ( ( V_79 < V_77 ) || ( V_77 == 0 ) ) {
if ( ( ( V_69 -> V_17 + 1 ) % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_69 -> V_17 + 1 ;
} else {
V_81 = V_69 -> V_17 + 1 ;
V_5 = 0 ;
while ( ( V_79 = V_57 -> V_17 - V_81 ) >= V_64 -> V_19 ) {
if ( ( V_81 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_81 ;
break;
}
V_81 += V_82 - V_81 % V_82 ;
if ( V_81 >= V_57 -> V_17 )
break;
}
}
if ( V_5 && V_77 == V_64 -> V_19 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
}
}
}
if ( V_70 ) {
if ( V_70 -> V_33 != V_69 -> V_33 ) {
V_79 = V_69 -> V_15 - 1 - V_57 -> V_15 ;
if ( ( V_69 -> V_15 != V_57 -> V_15 ) && ( V_79 >= V_64 -> V_19 ) ) {
if ( ( V_79 < V_77 ) || ( V_77 == 0 ) ) {
if ( ( V_57 -> V_15 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_57 -> V_15 ;
} else {
V_81 = V_57 -> V_15 ;
V_5 = 0 ;
while ( ( V_79 = V_69 -> V_15 - 1 - V_81 ) >= V_64 -> V_19 ) {
if ( ( V_81 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_81 ;
break;
}
V_81 += V_82 - V_81 % V_82 ;
if ( V_81 >= V_69 -> V_15 - 1 )
break;
}
}
if ( V_5 && V_77 == V_64 -> V_19 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
}
}
} else {
V_79 = V_69 -> V_15 - 1 - V_70 -> V_17 - 1 ;
if ( V_79 >= V_64 -> V_19 ) {
if ( ( V_79 < V_77 ) || ( V_77 == 0 ) ) {
if ( ( ( V_70 -> V_17 + 1 ) % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_70 -> V_17 + 1 ;
} else {
V_81 = V_70 -> V_17 + 1 ;
V_5 = 0 ;
while ( ( V_79 = V_69 -> V_15 - 1 - V_81 ) >= V_64 -> V_19 ) {
if ( ( V_81 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_81 ;
break;
}
V_81 += V_82 - V_81 % V_82 ;
if ( V_81 >= V_69 -> V_15 - 1 )
break;
}
}
if ( V_5 && V_77 == V_64 -> V_19 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
}
}
}
}
V_70 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
}
if ( ! V_70 ) {
switch ( V_64 -> type ) {
case V_31 :
V_57 = V_37 -> V_35 ;
break;
case V_27 :
V_57 = V_37 -> V_34 ;
break;
case V_29 :
V_57 = V_37 -> V_36 ;
break;
}
while ( V_57 ) {
V_79 = V_57 -> V_17 - V_57 -> V_15 ;
if ( V_79 >= V_64 -> V_19 ) {
if ( ( V_79 < V_77 ) || ( V_77 == 0 ) ) {
if ( ( V_57 -> V_15 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_57 -> V_15 ;
} else {
V_81 = V_57 -> V_15 ;
V_5 = 0 ;
while ( ( V_79 = V_57 -> V_17 - V_81 ) >= V_64 -> V_19 ) {
if ( ( V_81 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_81 ;
break;
}
V_81 += V_82 - V_81 % V_82 ;
if ( V_81 >= V_57 -> V_17 )
break;
}
}
if ( V_5 && V_77 == V_64 -> V_19 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
}
}
V_57 = V_57 -> V_63 ;
}
if ( ( ! V_57 ) && ( V_77 == 0 ) ) {
F_2 ( L_46 ) ;
return - V_73 ;
} else if ( V_77 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
}
if ( ! V_69 ) {
F_9 ( L_47 , V_70 -> V_33 , V_80 ) ;
if ( V_70 -> V_33 < V_80 ) {
switch ( V_64 -> type ) {
case V_31 :
V_57 = V_37 -> V_35 ;
break;
case V_27 :
V_57 = V_37 -> V_34 ;
break;
case V_29 :
V_57 = V_37 -> V_36 ;
break;
}
while ( V_57 ) {
V_79 = V_57 -> V_17 - V_57 -> V_15 ;
if ( V_79 >= V_64 -> V_19 ) {
if ( ( V_79 < V_77 ) || ( V_77 == 0 ) ) {
if ( ( V_57 -> V_15 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_57 -> V_15 ;
} else {
V_81 = V_57 -> V_15 ;
V_5 = 0 ;
while ( ( V_79 = V_57 -> V_17 - V_81 ) >= V_64 -> V_19 ) {
if ( ( V_81 % V_82 ) == 0 ) {
V_5 = 1 ;
V_77 = V_79 ;
V_78 = V_81 ;
break;
}
V_81 += V_82 - V_81 % V_82 ;
if ( V_81 >= V_57 -> V_17 )
break;
}
}
if ( V_5 && V_77 == V_64 -> V_19 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
}
}
V_57 = V_57 -> V_63 ;
}
if ( ( ! V_57 ) && ( V_77 == 0 ) ) {
F_2 ( L_46 ) ;
return - V_73 ;
} else if ( V_77 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
}
} else {
if ( V_77 ) {
V_64 -> V_15 = V_78 ;
V_64 -> V_19 += 1 ;
V_64 -> V_17 = V_64 -> V_15 + V_64 -> V_19 - 1 ;
return 0 ;
} else {
F_2 ( L_46 ) ;
return - V_73 ;
}
}
}
return - V_73 ;
}
int F_23 ( struct V_1 * V_85 , T_2 V_86 )
{
struct V_11 * V_69 ;
struct V_11 * V_87 ;
struct V_1 * V_88 ;
int V_42 ;
V_88 = F_14 ( V_86 , NULL , 0 ) ;
if ( ! V_88 ) {
F_9 ( L_48 ) ;
return - V_72 ;
}
F_9 ( L_49 , V_88 -> V_4 ) ;
V_42 = F_24 ( V_85 , V_88 ) ;
if ( V_42 )
return V_42 ;
if ( V_85 -> V_55 ) {
V_69 = V_85 -> V_55 ;
while ( V_69 ) {
V_87 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_85 -> V_55 = NULL ;
}
if ( V_85 -> V_50 ) {
V_69 = V_85 -> V_50 ;
while ( V_69 ) {
V_87 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_85 -> V_50 = NULL ;
}
if ( V_85 -> V_53 ) {
V_69 = V_85 -> V_53 ;
while ( V_69 ) {
V_87 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_85 -> V_53 = NULL ;
}
if ( V_85 -> V_75 ) {
V_69 = V_85 -> V_75 ;
while ( V_69 ) {
V_87 = V_69 ;
V_69 = V_69 -> V_63 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_85 -> V_75 = NULL ;
}
F_25 ( & V_85 -> V_9 ) ;
F_7 ( V_85 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_37 , struct V_1 * V_38 )
{
struct V_21 * V_58 ;
struct V_21 * V_89 ;
int V_90 ;
struct V_11 * V_64 = NULL ;
if ( V_37 -> V_32 ) {
V_58 = V_37 -> V_35 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_32 ; V_90 ++ ) {
if ( F_26 ( V_38 , V_58 -> V_15 , & V_64 , V_31 ) < 0 )
return - V_73 ;
F_20 ( V_64 ) ;
V_89 = V_58 ;
V_58 = V_58 -> V_63 ;
F_7 ( V_89 ) ;
V_89 = NULL ;
}
V_37 -> V_35 = NULL ;
}
if ( V_37 -> V_28 ) {
V_58 = V_37 -> V_34 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_28 ; V_90 ++ ) {
if ( F_26 ( V_38 , V_58 -> V_15 , & V_64 , V_27 ) < 0 )
return - V_73 ;
F_20 ( V_64 ) ;
V_89 = V_58 ;
V_58 = V_58 -> V_63 ;
F_7 ( V_89 ) ;
V_89 = NULL ;
}
V_37 -> V_34 = NULL ;
}
if ( V_37 -> V_30 ) {
V_58 = V_37 -> V_36 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_30 ; V_90 ++ ) {
if ( F_26 ( V_38 , V_58 -> V_15 , & V_64 , V_29 ) < 0 )
return - V_73 ;
F_20 ( V_64 ) ;
V_89 = V_58 ;
V_58 = V_58 -> V_63 ;
F_7 ( V_89 ) ;
V_89 = NULL ;
}
V_37 -> V_36 = NULL ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_85 , T_3 V_91 , struct V_11 * * V_64 , int V_5 )
{
struct V_11 * V_69 = NULL ;
char * type = L_19 ;
if ( ! V_85 ) {
F_2 ( L_50 ) ;
return - V_72 ;
}
switch ( V_5 ) {
case V_31 :
V_69 = V_85 -> V_55 ;
type = L_20 ;
break;
case V_27 :
V_69 = V_85 -> V_50 ;
type = L_21 ;
break;
case V_29 :
V_69 = V_85 -> V_53 ;
type = L_22 ;
break;
default:
F_2 ( L_51 ) ;
return - V_73 ;
}
while ( V_69 ) {
if ( V_69 -> V_15 == V_91 ) {
* V_64 = V_69 ;
break;
}
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
}
if ( ! V_69 ) {
if ( V_5 == V_29 ) {
V_69 = V_85 -> V_75 ;
while ( V_69 ) {
if ( V_69 -> V_15 == V_91 ) {
* V_64 = V_69 ;
break;
}
V_69 = V_69 -> V_63 ;
}
if ( ! V_69 ) {
F_9 ( L_52 , type ) ;
return - V_73 ;
}
} else {
F_9 ( L_53 , type ) ;
return - V_73 ;
}
}
if ( * V_64 )
F_9 ( L_54 , ( * V_64 ) -> V_15 ) ;
return 0 ;
}
void F_27 ( void )
{
struct V_1 * V_37 = NULL , * V_63 ;
struct V_1 * V_92 ;
struct V_21 * V_58 ;
struct V_21 * V_89 ;
struct V_11 * V_69 ;
struct V_11 * V_87 ;
int V_90 = 0 ;
V_93 = 1 ;
F_28 (bus_cur, next, &gbuses, bus_list) {
if ( V_37 -> V_32 ) {
V_58 = V_37 -> V_35 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_32 ; V_90 ++ ) {
if ( ! V_58 )
break;
V_89 = V_58 ;
V_58 = V_58 -> V_63 ;
F_7 ( V_89 ) ;
V_89 = NULL ;
}
}
if ( V_37 -> V_28 ) {
V_58 = V_37 -> V_34 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_28 ; V_90 ++ ) {
if ( ! V_58 )
break;
V_89 = V_58 ;
V_58 = V_58 -> V_63 ;
F_7 ( V_89 ) ;
V_89 = NULL ;
}
}
if ( V_37 -> V_30 ) {
V_58 = V_37 -> V_36 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_30 ; V_90 ++ ) {
if ( ! V_58 )
break;
V_89 = V_58 ;
V_58 = V_58 -> V_63 ;
F_7 ( V_89 ) ;
V_89 = NULL ;
}
}
if ( V_37 -> V_55 ) {
V_69 = V_37 -> V_55 ;
while ( V_69 ) {
V_87 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_37 -> V_55 = NULL ;
}
if ( V_37 -> V_50 ) {
V_69 = V_37 -> V_50 ;
while ( V_69 ) {
V_87 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_37 -> V_50 = NULL ;
}
if ( V_37 -> V_53 ) {
V_69 = V_37 -> V_53 ;
while ( V_69 ) {
V_87 = V_69 ;
if ( V_69 -> V_63 )
V_69 = V_69 -> V_63 ;
else
V_69 = V_69 -> V_66 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_37 -> V_53 = NULL ;
}
if ( V_37 -> V_75 ) {
V_69 = V_37 -> V_75 ;
while ( V_69 ) {
V_87 = V_69 ;
V_69 = V_69 -> V_63 ;
F_7 ( V_87 ) ;
V_87 = NULL ;
}
V_37 -> V_75 = NULL ;
}
V_92 = V_37 ;
F_25 ( & V_37 -> V_9 ) ;
F_7 ( V_92 ) ;
V_92 = NULL ;
}
}
static int T_1 F_17 ( void )
{
struct V_11 * V_94 ;
struct V_11 * V_95 ;
struct V_11 * V_96 ;
struct V_1 * V_37 ;
F_12 (bus_cur, &gbuses, bus_list) {
if ( ( ! V_37 -> V_36 ) && ( V_37 -> V_53 ) ) {
for ( V_94 = V_37 -> V_53 , V_95 = NULL ; V_94 ; V_95 = V_94 , V_94 = V_94 -> V_63 ) {
V_94 -> V_52 = 1 ;
if ( V_95 )
V_95 -> V_63 = V_94 -> V_63 ;
else
V_37 -> V_53 = V_94 -> V_63 ;
if ( ! V_37 -> V_75 )
V_94 -> V_63 = NULL ;
else
V_94 -> V_63 = V_37 -> V_75 ;
V_37 -> V_75 = V_94 ;
V_96 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_96 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_96 -> type = V_27 ;
V_96 -> V_4 = V_94 -> V_4 ;
V_96 -> V_13 = V_94 -> V_13 ;
V_96 -> V_15 = V_94 -> V_15 ;
V_96 -> V_17 = V_94 -> V_17 ;
V_96 -> V_19 = V_94 -> V_19 ;
if ( F_15 ( V_96 ) < 0 )
F_2 ( L_55 ) ;
V_94 -> V_33 = V_96 -> V_33 ;
}
}
}
return 0 ;
}
int F_29 ( struct V_11 * V_97 )
{
struct V_1 * V_37 = F_14 ( V_97 -> V_4 , NULL , 0 ) ;
if ( ! V_37 ) {
F_2 ( L_56 ) ;
return - V_72 ;
}
if ( V_37 -> V_75 )
V_97 -> V_63 = V_37 -> V_75 ;
else
V_97 -> V_63 = NULL ;
V_37 -> V_75 = V_97 ;
return 0 ;
}
struct V_1 * F_30 ( T_2 V_98 )
{
return F_14 ( V_98 , NULL , 0 ) ;
}
static struct V_1 * F_14 ( T_2 V_98 , struct V_1 * * V_99 , T_2 V_5 )
{
struct V_1 * V_37 ;
F_12 (bus_cur, &gbuses, bus_list) {
if ( V_5 )
* V_99 = F_31 ( V_37 , V_9 ) ;
if ( V_37 -> V_4 == V_98 )
return V_37 ;
}
return NULL ;
}
void F_32 ( void )
{
int V_90 = 0 ;
struct V_1 * V_37 = NULL ;
struct V_21 * V_57 ;
struct V_11 * V_64 ;
F_33 ( L_57 ) ;
if ( ( ! F_13 ( & V_10 ) ) && V_93 ) {
F_2 ( L_58 ) ;
return;
}
F_12 (bus_cur, &gbuses, bus_list) {
F_33 ( L_59 , V_37 -> V_4 ) ;
F_33 ( L_60 , V_37 -> V_32 ) ;
F_33 ( L_61 , V_37 -> V_28 ) ;
F_33 ( L_62 , V_37 -> V_30 ) ;
F_33 ( L_63 ) ;
if ( V_37 -> V_35 ) {
V_57 = V_37 -> V_35 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_32 ; V_90 ++ ) {
F_33 ( L_64 , V_57 -> V_33 ) ;
F_33 ( L_65 , V_57 -> V_15 , V_57 -> V_17 ) ;
V_57 = V_57 -> V_63 ;
}
}
F_33 ( L_66 ) ;
if ( V_37 -> V_34 ) {
V_57 = V_37 -> V_34 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_28 ; V_90 ++ ) {
F_33 ( L_64 , V_57 -> V_33 ) ;
F_33 ( L_65 , V_57 -> V_15 , V_57 -> V_17 ) ;
V_57 = V_57 -> V_63 ;
}
}
F_33 ( L_67 ) ;
if ( V_37 -> V_36 ) {
V_57 = V_37 -> V_36 ;
for ( V_90 = 0 ; V_90 < V_37 -> V_30 ; V_90 ++ ) {
F_33 ( L_64 , V_57 -> V_33 ) ;
F_33 ( L_65 , V_57 -> V_15 , V_57 -> V_17 ) ;
V_57 = V_57 -> V_63 ;
}
}
F_33 ( L_68 ) ;
F_33 ( L_69 ) ;
if ( V_37 -> V_55 ) {
V_64 = V_37 -> V_55 ;
while ( V_64 ) {
F_33 ( L_70 , V_64 -> V_33 ) ;
F_33 ( L_71 , V_64 -> V_4 , V_64 -> V_13 ) ;
F_33 ( L_72 , V_64 -> V_15 , V_64 -> V_17 , V_64 -> V_19 ) ;
if ( V_64 -> V_63 )
V_64 = V_64 -> V_63 ;
else if ( V_64 -> V_66 )
V_64 = V_64 -> V_66 ;
else
break;
}
}
F_33 ( L_73 ) ;
if ( V_37 -> V_50 ) {
V_64 = V_37 -> V_50 ;
while ( V_64 ) {
F_33 ( L_70 , V_64 -> V_33 ) ;
F_33 ( L_71 , V_64 -> V_4 , V_64 -> V_13 ) ;
F_33 ( L_72 , V_64 -> V_15 , V_64 -> V_17 , V_64 -> V_19 ) ;
if ( V_64 -> V_63 )
V_64 = V_64 -> V_63 ;
else if ( V_64 -> V_66 )
V_64 = V_64 -> V_66 ;
else
break;
}
}
F_33 ( L_74 ) ;
if ( V_37 -> V_53 ) {
V_64 = V_37 -> V_53 ;
while ( V_64 ) {
F_33 ( L_70 , V_64 -> V_33 ) ;
F_33 ( L_71 , V_64 -> V_4 , V_64 -> V_13 ) ;
F_33 ( L_72 , V_64 -> V_15 , V_64 -> V_17 , V_64 -> V_19 ) ;
if ( V_64 -> V_63 )
V_64 = V_64 -> V_63 ;
else if ( V_64 -> V_66 )
V_64 = V_64 -> V_66 ;
else
break;
}
}
F_33 ( L_75 ) ;
if ( V_37 -> V_75 ) {
V_64 = V_37 -> V_75 ;
while ( V_64 ) {
F_33 ( L_70 , V_64 -> V_33 ) ;
F_33 ( L_71 , V_64 -> V_4 , V_64 -> V_13 ) ;
F_33 ( L_72 , V_64 -> V_15 , V_64 -> V_17 , V_64 -> V_19 ) ;
V_64 = V_64 -> V_63 ;
}
}
}
F_33 ( L_76 ) ;
}
static int F_34 ( struct V_21 * V_57 , struct V_1 * V_37 , T_2 type )
{
struct V_21 * V_58 = NULL ;
switch ( type ) {
case V_31 :
V_58 = V_37 -> V_35 ;
break;
case V_27 :
V_58 = V_37 -> V_34 ;
break;
case V_29 :
V_58 = V_37 -> V_36 ;
break;
default:
F_2 ( L_77 ) ;
return - V_72 ;
}
while ( V_58 ) {
if ( ( V_58 -> V_15 == V_57 -> V_15 ) && ( V_58 -> V_17 == V_57 -> V_17 ) )
return 1 ;
V_58 = V_58 -> V_63 ;
}
return 0 ;
}
static int T_1 F_16 ( struct V_1 * * V_85 )
{
T_2 V_100 , V_101 , V_102 , V_103 , V_104 , V_105 ;
T_4 V_106 , V_107 , V_108 , V_109 , V_110 ;
T_3 V_91 , V_111 , V_112 , V_113 ;
struct V_1 * V_114 ;
struct V_1 * V_37 ;
struct V_11 * V_115 ;
struct V_11 * V_96 ;
struct V_11 * V_97 ;
struct V_21 * V_57 ;
unsigned int V_116 ;
V_37 = * V_85 ;
if ( ! V_37 )
return - V_72 ;
V_117 -> V_118 = V_37 -> V_4 ;
F_9 ( L_78 , V_68 ) ;
F_9 ( L_79 , V_37 -> V_4 ) ;
for ( V_101 = 0 ; V_101 < 32 ; V_101 ++ ) {
for ( V_102 = 0x00 ; V_102 < 0x08 ; V_102 ++ ) {
V_116 = F_35 ( V_101 , V_102 ) ;
F_36 ( V_117 , V_116 , V_119 , & V_106 ) ;
if ( V_106 != V_120 ) {
F_37 ( V_117 , V_116 , V_121 , & V_103 ) ;
switch ( V_103 ) {
case V_122 :
V_102 = 0x8 ;
break;
case V_123 :
break;
case V_124 :
V_102 = 0x8 ;
case V_125 :
F_37 ( V_117 , V_116 , V_126 , & V_100 ) ;
V_114 = F_14 ( V_100 , NULL , 0 ) ;
if ( ! V_114 ) {
V_114 = F_1 ( NULL , V_100 , 1 ) ;
return 0 ;
}
F_37 ( V_117 , V_116 , V_127 , & V_104 ) ;
F_37 ( V_117 , V_116 , V_128 , & V_105 ) ;
F_36 ( V_117 , V_116 , V_129 , & V_107 ) ;
F_36 ( V_117 , V_116 , V_130 , & V_108 ) ;
V_91 = ( V_104 & V_131 ) << 8 ;
V_91 |= ( V_107 << 16 ) ;
V_111 = ( V_105 & V_131 ) << 8 ;
V_111 |= ( V_108 << 16 ) ;
if ( ( V_91 ) && ( V_91 <= V_111 ) ) {
V_57 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_57 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_57 -> V_15 = V_91 ;
V_57 -> V_17 = V_111 + 0xfff ;
if ( V_114 -> V_32 > 0 ) {
if ( ! F_34 ( V_57 , V_114 , V_31 ) ) {
F_8 ( V_31 , V_57 , V_114 ) ;
++ V_114 -> V_32 ;
} else {
F_7 ( V_57 ) ;
V_57 = NULL ;
}
} else {
V_57 -> V_33 = 1 ;
V_114 -> V_35 = V_57 ;
++ V_114 -> V_32 ;
}
F_10 ( V_114 ) ;
if ( F_26 ( V_37 , V_91 , & V_115 , V_31 ) ) {
V_115 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_115 ) {
F_7 ( V_57 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_115 -> type = V_31 ;
V_115 -> V_4 = V_37 -> V_4 ;
V_115 -> V_13 = ( ( V_101 << 3 ) | ( V_102 & 0x7 ) ) ;
V_115 -> V_15 = V_91 ;
V_115 -> V_17 = V_111 + 0xfff ;
V_115 -> V_19 = V_115 -> V_17 - V_115 -> V_15 + 1 ;
F_15 ( V_115 ) ;
}
}
F_36 ( V_117 , V_116 , V_132 , & V_109 ) ;
F_36 ( V_117 , V_116 , V_133 , & V_110 ) ;
V_91 = 0x00000000 | ( V_109 & V_134 ) << 16 ;
V_111 = 0x00000000 | ( V_110 & V_134 ) << 16 ;
if ( ( V_91 ) && ( V_91 <= V_111 ) ) {
V_57 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_57 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_57 -> V_15 = V_91 ;
V_57 -> V_17 = V_111 + 0xfffff ;
if ( V_114 -> V_28 > 0 ) {
if ( ! F_34 ( V_57 , V_114 , V_27 ) ) {
F_8 ( V_27 , V_57 , V_114 ) ;
++ V_114 -> V_28 ;
} else {
F_7 ( V_57 ) ;
V_57 = NULL ;
}
} else {
V_57 -> V_33 = 1 ;
V_114 -> V_34 = V_57 ;
++ V_114 -> V_28 ;
}
F_10 ( V_114 ) ;
if ( F_26 ( V_37 , V_91 , & V_96 , V_27 ) ) {
V_96 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_96 ) {
F_7 ( V_57 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_96 -> type = V_27 ;
V_96 -> V_4 = V_37 -> V_4 ;
V_96 -> V_13 = ( ( V_101 << 3 ) | ( V_102 & 0x7 ) ) ;
V_96 -> V_15 = V_91 ;
V_96 -> V_17 = V_111 + 0xfffff ;
V_96 -> V_19 = V_96 -> V_17 - V_96 -> V_15 + 1 ;
F_15 ( V_96 ) ;
}
}
F_36 ( V_117 , V_116 , V_135 , & V_109 ) ;
F_36 ( V_117 , V_116 , V_136 , & V_110 ) ;
F_38 ( V_117 , V_116 , V_137 , & V_112 ) ;
F_38 ( V_117 , V_116 , V_138 , & V_113 ) ;
V_91 = 0x00000000 | ( V_109 & V_134 ) << 16 ;
V_111 = 0x00000000 | ( V_110 & V_134 ) << 16 ;
#if V_139 == 64
V_91 |= ( ( long ) V_112 ) << 32 ;
V_111 |= ( ( long ) V_113 ) << 32 ;
#endif
if ( ( V_91 ) && ( V_91 <= V_111 ) ) {
V_57 = F_3 ( sizeof( struct V_21 ) , V_7 ) ;
if ( ! V_57 ) {
F_2 ( L_2 ) ;
return - V_26 ;
}
V_57 -> V_15 = V_91 ;
V_57 -> V_17 = V_111 + 0xfffff ;
if ( V_114 -> V_30 > 0 ) {
if ( ! F_34 ( V_57 , V_114 , V_29 ) ) {
F_8 ( V_29 , V_57 , V_114 ) ;
++ V_114 -> V_30 ;
} else {
F_7 ( V_57 ) ;
V_57 = NULL ;
}
} else {
V_57 -> V_33 = 1 ;
V_114 -> V_36 = V_57 ;
++ V_114 -> V_30 ;
}
F_10 ( V_114 ) ;
if ( F_26 ( V_37 , V_91 , & V_97 , V_29 ) ) {
V_97 = F_3 ( sizeof( struct V_11 ) , V_7 ) ;
if ( ! V_97 ) {
F_7 ( V_57 ) ;
F_2 ( L_2 ) ;
return - V_26 ;
}
V_97 -> type = V_29 ;
V_97 -> V_4 = V_37 -> V_4 ;
V_97 -> V_13 = ( ( V_101 << 3 ) | ( V_102 & 0x7 ) ) ;
V_97 -> V_15 = V_91 ;
V_97 -> V_17 = V_111 + 0xfffff ;
V_97 -> V_19 = V_97 -> V_17 - V_97 -> V_15 + 1 ;
V_97 -> V_52 = 0 ;
F_15 ( V_97 ) ;
}
}
break;
}
}
}
}
V_85 = & V_37 ;
return 0 ;
}
